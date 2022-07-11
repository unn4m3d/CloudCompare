#include <ccAdvancedAPI.h>

ccAdvancedAPI::ccAdvancedAPI(QObject* parent) :
    QObject(parent)
    {}

void ccAdvancedAPI::initialize()
{
    Q_EMIT initialized();
}

void ccAdvancedAPI::triggerActionCompleted(QString id, const QObject* results)
{
    Q_EMIT actionCompleted(id, results);
}

ccAdvancedAPI::~ccAdvancedAPI()
{}