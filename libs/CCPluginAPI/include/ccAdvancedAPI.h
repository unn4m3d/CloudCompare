#pragma once
#include "CCPluginAPI.h"
#include <QObject>

class CCPLUGIN_LIB_API ccAdvancedAPI : public QObject
{
    Q_OBJECT
public:
    ccAdvancedAPI(QObject* parent = nullptr);

    void initialize();
    virtual ~ccAdvancedAPI();

    void triggerActionCompleted(QString id, const QObject* results);

public signals:
    void initialized();
    void actionCompleted(QString id, const QObject* results);

public slots:
    void launchAction(QString id, const QObject* settings);
    
    
};