#pragma once
#include <vb/field.hpp>

namespace advapi
{
    struct ComputeKdTreeParams
    {
        enum list
        {
            Leaf,
            Auto
        };

        template<typename T, list Name>
        using Field = vb::Field<T, list, Name>;

        Field<double, Leaf> leaf;
        Field<bool, Auto> _auto;
    };
}