#pragma once
#include <vb/field.hpp>

namespace advapi
{
    struct AutoOnlyParams
    {
        enum list 
        {
            Auto
        };

        template<typename T, list Name>
        using Field = vb::Field<T, list, Name>;
        
        Field<bool, Auto> _auto;
    };
}