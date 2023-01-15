#include <ccAdvancedAPI.h> 
#include <iostream>

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

void ccAdvancedAPI::setParams(const QString& action, std::shared_ptr<vb::SerializableHolder> params)
{
    m_params[action] = params;
    std::cerr << "Set params for " << action.toStdString() << ":" << typeid(params.get()).name() << ":" << (long long unsigned)params.get()  << ":" << params->type_name() << std::endl;
}

std::shared_ptr<vb::SerializableHolder> ccAdvancedAPI::getParams(const QString& action)
{
    auto params = m_params[action];
    std::cerr << "Get params for " << action.toStdString() << ":" << typeid(params.get()).name()  << ":" << (long long unsigned)params.get() << ":" << params->type_name() << std::endl;
    return m_params[action];
}


