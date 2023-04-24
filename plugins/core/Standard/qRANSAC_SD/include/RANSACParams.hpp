#pragma once

#include <vb/field.hpp>


namespace advapi
{
    struct RANSACParams
    {
        enum list
        {
            Plane,
            Sphere,
            Torus,
            Cone,
            Cylinder,
            MinSupportPoints,
            MaxDistance,
            Resolution,
            MaxDeviation,
            Overlooking,
            MinSphereRadius,
            MaxSphereRadius,
            MinCylinderRadius,
            MaxCylinderRadius,
            MinTorusMinorRadius,
            MaxTorusMinorRadius,
            MinTorusMajorRadius,
            MaxTorusMajorRadius,
            Auto
        };

        template<typename T, list Name>
        using Field = vb::Field<T, list, Name>;

        Field<bool, Sphere> sphere;
        Field<bool, Plane> plane;
        Field<bool, Torus> torus;
        Field<bool, Cone> cone;
        Field<bool, Cylinder> cylinder;
        Field<int, MinSupportPoints> minSupportPoints;
        Field<double, MaxDistance> maxDistance;
        Field<double, Resolution> resolution;
        Field<double, MaxDeviation> maxDeviation;
        Field<double, Overlooking> overlooking;
        Field<double, MinSphereRadius> minSphereRadius;
        Field<double, MaxSphereRadius> maxSphereRadius;
        Field<double, MinCylinderRadius> minCylinderRadius;
        Field<double, MaxCylinderRadius> maxCylinderRadius;
        Field<double, MinTorusMinorRadius> minTorusMinorRadius;
        Field<double, MaxTorusMinorRadius> maxTorusMinorRadius;
        Field<double, MinTorusMajorRadius> minTorusMajorRadius;
        Field<double, MaxTorusMajorRadius> maxTorusMajorRadius;
        Field<bool, Auto> _auto;
    };
}