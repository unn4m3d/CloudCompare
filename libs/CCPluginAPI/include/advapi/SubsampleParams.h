#pragma once
#include <vb/field.hpp>

namespace advapi
{
    struct SubsampleParams
    {
        enum list 
        {
            Method,
            Value
        };

        template<typename T, list Name>
        using Field = vb::Field<T, list, Name>;

        Field<int, Method> method;
        Field<double, Value> value;
    };
}