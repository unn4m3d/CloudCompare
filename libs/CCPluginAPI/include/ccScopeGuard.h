#pragma once
#include "CCPluginAPI.h"
#include <functional>
//! A simple scope exit guard
class CCPLUGIN_LIB_API ccScopeGuard
{
public:
    ccScopeGuard(std::function<void()>&&);
    ~ccScopeGuard();
private:
    std::function<void()> m_function;
};