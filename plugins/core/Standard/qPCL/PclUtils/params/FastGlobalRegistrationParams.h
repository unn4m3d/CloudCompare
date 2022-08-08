#pragma once
#include <vb/field.hpp>

namespace advapi
{
    struct FastGlobalRegistrationParams
    {
        enum list
        {
            FeatureRadius,
            Auto
        };

        template<typename T, list Name>
        using Field = vb::Field<T, list, Name>;

        Field<double, FeatureRadius> featureRadius;
        Field<bool, Auto> _auto;
    };
}