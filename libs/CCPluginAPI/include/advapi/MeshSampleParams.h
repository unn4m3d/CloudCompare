#pragma once
#include <vb/field.hpp>

namespace advapi
{
    struct MeshSampleParams
    {
        enum list 
        {
            UseDensity,
            Number,
            Density
        };

        template<typename T, list Name>
        using Field = vb::Field<T, list, Name>;

        Field<bool, UseDensity> useDensity;
        Field<int, Number> number;
        Field<double, Density> density;
    };
}