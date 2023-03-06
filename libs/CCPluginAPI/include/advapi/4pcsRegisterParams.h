#pragma once
#include <vb/field.hpp>

namespace advapi
{
    struct _4pcsRegisterParams
    {
        enum list 
        {
            NTrials,
            Overlap,
            Delta,
            NMaxCandidates,
            SamplingMethod,
            DataSamplingRate,
            ModelSamplingRate,
            Auto
        };

        template<typename T, list Name>
        using Field = vb::Field<T, list, Name>;

        Field<int, NTrials> nTrials;
        Field<double, Overlap> overlap;
        Field<int, NMaxCandidates> nMaxCandidates;
        Field<int, SamplingMethod> samplingMethod;
        Field<double, DataSamplingRate> dataSamplingRate;
        Field<double, ModelSamplingRate> modelSamplingRate;
    };
}