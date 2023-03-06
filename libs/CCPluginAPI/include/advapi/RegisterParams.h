#pragma once
#include <vb/field.hpp>

namespace advapi
{
    struct RegisterParams
    {
        enum list 
        {
            NIter,
            RMSDiff,
            FinalOverlap,
            AdjustScale,
            MaxThreads,
            RandomSamplingLimit,
            Rotation,
            TX, TY, TZ,
            EnableFPR,
            Auto
        };

        template<typename T, list Name>
        using Field = vb::Field<T, list, Name>;

        Field<int, NIter> nIter;
        Field<double, RMSDiff> rmsDiff;
        Field<double, FinalOverlap> finalOverlap;
        Field<bool, AdjustScale> adjustScale;
        Field<int, MaxThreads> maxThreads;
        Field<int, RandomSamplingLimit> randomSamplingLimit;
        Field<int, Rotation> rotation;
        Field<bool, TX> tX;
        Field<bool, TY> tY;
        Field<bool, TZ> tZ;
        Field<bool, EnableFPR> enableFPR;
        Field<bool, Auto> _auto;
    };
}