#include "ccScopeGuard.h"

ccScopeGuard::ccScopeGuard(std::function<void()>&& func) :
    m_function(func)
    {}

ccScopeGuard::~ccScopeGuard()
{
    m_function();
}