#pragma once
#include <vb/nameof.hpp>
#include <string_view>

namespace vb
{
    // Just an empty base class to use dynamic casts
    struct SerializableHolder {};

    template<typename T>
    struct Serializable : SerializableHolder
    {
        T value;
    };

    template<typename T, typename E, E Name>
    struct Field
    {
        T value;
        bool present;

        operator T&() { return value; }
        operator T() { return value; }
    };

    namespace detail
    {
        enum NotAField { NONE };

        template<typename T, typename E = NotAField, E Name = NONE>
        struct FieldTraits
        {
            static std::string_view fieldName()
            {
                return NAMEOF_ENUM(Name);
            }

            static constexpr bool isField = false;
        };

        template<typename T, typename E, E Name>
        struct FieldTraits<Field<T, E, Name>>
        {
            static std::string_view fieldName()
            {
                return FieldTraits<T, E, Name>::fieldName();
            }

            static constexpr bool isField = true;
        };

    }

    template<typename T>
    inline auto fieldName()
    {
        return detail::FieldTraits<std::remove_cvref_t<T>>::fieldName();
    }

    template<typename T>
    constexpr bool isField = detail::FieldTraits<std::remove_cvref_t<T>>::isField;


}