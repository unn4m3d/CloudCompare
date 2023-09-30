#pragma once
#include <vb/field.hpp>

namespace advapi
{
    struct MergeParams
    {
        enum list 
        {
            GenerateIndex,
            Auto
        };

        template<typename T, list Name>
        using Field = vb::Field<T, list, Name>;

        Field<bool, GenerateIndex> generateIndex;
        Field<bool, Auto> _auto;
    };
}