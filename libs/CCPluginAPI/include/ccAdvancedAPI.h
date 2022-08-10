#pragma once
#include "CCPluginAPI.h"
#include <QObject>
#include <QVariant>
#include "ccAdvancedAPISigDecl.h"
#include "advapi_impl/settings.hpp"

class ccHObject;
class ccPluginUIManager;
class ccPluginInterface;

class CCPLUGIN_LIB_API ccAdvancedAPI : public ccAdvancedAPISigDecl
{
    Q_OBJECT
public:
    ccAdvancedAPI(QObject* parent = nullptr);

    void initialize();
    virtual ~ccAdvancedAPI();

    void triggerActionCompleted(QString id, QVariant results);
    void triggerActionFailed(QString id, QString reason);
    void triggerActionCanceled(QString id);

    QVariant& getSettings()
    {
        return m_currentSettings;
    }

Q_SIGNALS:
    void initialized();

    void actionCompleted(QString id, QVariant results);
    void actionFailed(QString id, QString reason);
    void actionCanceled(QString id);
    
    void addedToDB(ccHObject*);

    void actionTriggered(QString);
    void actionFinished(QString);

public Q_SLOTS:
    void launchAction(QString id, const QVariant& settings);

    void notImplemented(QString id);

private:
    QVariant m_currentSettings;
    
};