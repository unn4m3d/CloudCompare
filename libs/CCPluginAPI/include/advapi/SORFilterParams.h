#pragma once
#include <vb/field.hpp>

namespace advapi
{
    struct SORFilterParams
    {
        enum list 
        {
            NPoints,
            Sigma
        };

        template<typename T, list Name>
        using Field = vb::Field<T, list, Name>;

        Field<int, NPoints> nPoints;
        Field<double, Sigma> sigma;
    };
}