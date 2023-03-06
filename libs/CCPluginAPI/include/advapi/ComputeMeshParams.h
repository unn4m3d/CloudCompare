#pragma once
#include <vb/field.hpp>

namespace advapi
{
    struct ComputeMeshParams
    {
        enum list
        {
            Edge,
            Auto
        };

        template<typename T, list Name>
        using Field = vb::Field<T, list, Name>;

        Field<double, Edge> edge;
        Field<bool, Auto> _auto;
    };
}