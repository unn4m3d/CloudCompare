#pragma once
#include <vb/field.hpp>

namespace advapi
{
    struct NormalEstimationParams
    {
        enum list
        {
            KNNRadius,
            Radius,
            UseKNN,
            OverwriteCurvature,
            Auto
        };

        template<typename T, list Name>
        using Field = vb::Field<T, list, Name>;

        Field<double, KNNRadius> knnRadius;
        Field<double, Radius> radius;
        Field<bool, UseKNN> useKnn;
        Field<bool, OverwriteCurvature> overwriteCurvature;
        Field<bool, Auto> _auto;
    };
}