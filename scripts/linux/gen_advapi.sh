#!/bin/bash

DIRNAME=$(dirname $0)/../../
MAINWINDOW_CPP=$DIRNAME/qCC/mainwindow.cpp
CC_ADVAPI_DIR=$DIRNAME/libs/CCPluginAPI/include/advapi_impl
CC_SIGDECL=$CC_ADVAPI_DIR/../ccAdvancedAPISigDecl.h
CC_CONNECT=$CC_ADVAPI_DIR/advapi_connect.h
CC_SWITCH=$CC_ADVAPI_DIR/advapi_switch.h
CC_SIGDECL_HEADER=$(dirname $0)/advapi_sigdecl_hdr.txt
CC_CANCEL_ACTIONS=$(dirname $0)/advapi_cancel_actions.txt
CC_SWITCH_VAR_NAME=action

# TODO: Use hashtable to select actions

mkdir -p $CC_ADVAPI_DIR
cat $CC_SIGDECL_HEADER > $CC_SIGDECL
echo > $CC_CONNECT
echo > $CC_SWITCH

for action in $(grep 'void MainWindow::doAction' $MAINWINDOW_CPP | sed 's/.*doAction//g' | sed 's/[^a-zA-Z0-9].*//g')
do
    slot="doAction$action"

    for cancel in $(cat $CC_CANCEL_ACTIONS)
    do
        if [ "$cancel" = "$action" ]
        then
            slot=notImplemented
        fi
    done

    if [ "$slot" != "notImplemented" ]
    then
        echo "connect(&m_advancedAPI, &ccAdvancedAPI::doAction$action, this, &MainWindow::$slot);" >> $CC_CONNECT
        echo "    void doAction$action();" >> $CC_SIGDECL
        echo "if($CC_SWITCH_VAR_NAME == \"$action\"){ Q_EMIT $slot(); return; }" >> $CC_SWITCH
    fi
done

echo "};" >> $CC_SIGDECL

