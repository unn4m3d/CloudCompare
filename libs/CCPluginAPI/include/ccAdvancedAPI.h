#pragma once
#include "CCPluginAPI.h"
#include <QObject>
#include <QVariant>

class ccHObject;

class CCPLUGIN_LIB_API ccAdvancedAPI : public QObject
{
    Q_OBJECT
public:
    ccAdvancedAPI(QObject* parent = nullptr);

    void initialize();
    virtual ~ccAdvancedAPI();

    void triggerActionCompleted(QString id, QVariant results);
    void triggerActionFailed(QString id, QString reason);
    void triggerActionCanceled(QString id);

Q_SIGNALS:
    void initialized();

    void actionCompleted(QString id, QVariant results);
    void actionFailed(QString id, QString reason);
    void actionCanceled(QString id);
    
    void addedToDB(ccHObject*);

    void doActionRegister();
    void doAction4pcsRegister();
    void doActionSubsample();
    void doActionSORFilter();
    void doActionCloudMeshDist();

public Q_SLOTS:
    void launchAction(QString id, QVariant settings);
    
    
};