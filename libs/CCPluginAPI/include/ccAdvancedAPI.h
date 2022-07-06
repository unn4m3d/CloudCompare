#pragma once
#include "CCPluginAPI.h"
#include <QObject>

class CCPLUGIN_LIB_API ccAdvancedAPI : public QObject
{
    Q_OBJECT
public:
    ccAdvancedAPI(QObject* parent = nullptr);
    void initialize();
    Q_SIGNAL void initialized();
    virtual ~ccAdvancedAPI();
};