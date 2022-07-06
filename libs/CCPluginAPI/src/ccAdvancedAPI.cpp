#include <ccAdvancedAPI.h>

ccAdvancedAPI::ccAdvancedAPI(QObject* parent) :
    QObject(parent)
    {}

void ccAdvancedAPI::initialize()
{
    Q_EMIT initialized();
}

ccAdvancedAPI::~ccAdvancedAPI()
{}