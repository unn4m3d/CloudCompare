#pragma once
#include <vb/nameof.hpp>
#include <vb/field.hpp>
#include <boost/pfr.hpp>
#include <functional>
#include <QWidget>
#include <type_traits>
#include <QVector>
namespace vb
{

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

            using FieldType = void;
        };

        template<typename T, typename E, E Name>
        struct FieldTraits<Field<T, E, Name>>
        {
            static std::string_view fieldName()
            {
                return FieldTraits<T, E, Name>::fieldName();
            }

            static constexpr bool isField = true;

            using FieldType = T;
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