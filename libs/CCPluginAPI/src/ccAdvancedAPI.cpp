#include <ccAdvancedAPI.h> 

ccAdvancedAPI::ccAdvancedAPI(QObject* parent) :
    ccAdvancedAPISigDecl(parent)
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

void ccAdvancedAPI::launchAction(QString action, QVariant settings)
{
    #include "advapi_impl/advapi_switch.h"
    
    Q_EMIT notImplemented(action);
}

ccAdvancedAPI::~ccAdvancedAPI()
{}

void ccAdvancedAPI::notImplemented(QString id)
{
    Q_EMIT actionFailed(id, "Action is missing or not implemented");
}
