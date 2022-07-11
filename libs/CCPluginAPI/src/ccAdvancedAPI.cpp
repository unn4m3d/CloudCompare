#include <ccAdvancedAPI.h>

ccAdvancedAPI::ccAdvancedAPI(QObject* parent) :
    QObject(parent)
    {}

void ccAdvancedAPI::initialize()
{
    Q_EMIT initialized();
}

void ccAdvancedAPI::triggerActionCompleted(QString id, QVariant results)
{
    Q_EMIT actionCompleted(id, results);
}

void ccAdvancedAPI::triggerActionFailed(QString id, QString message)
{
    Q_EMIT actionFailed(id, message);
}

void ccAdvancedAPI::triggerActionCanceled(QString id)
{
    Q_EMIT actionCanceled(id);
}

void ccAdvancedAPI::launchAction(QString id, QVariant settings)
{
    if(id == "Register")
        Q_EMIT doActionRegister();
    else if(id == "4pcsRegister")
        Q_EMIT doAction4pcsRegister();
    else if(id == "Subsample")
        Q_EMIT doActionSubsample();
    else if(id == "SORFilter")
        Q_EMIT doActionSORFilter();
    else if(id == "CloudMeshDist")
        Q_EMIT doActionCloudMeshDist();
    else
        Q_EMIT actionFailed(id, "Action is missing or not implemented");
}

ccAdvancedAPI::~ccAdvancedAPI()
{}