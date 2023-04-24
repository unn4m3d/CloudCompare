#pragma once
#include <QVariant>
#include <QSettings>
#include <vb/field_traits.hpp>
#include <boost/pfr.hpp>

namespace vb
{
    namespace detail
    {
        template<typename T>
        static inline T convert(const QVariant& value)
        {
            using Type = std::remove_cvref_t<T>;
            if constexpr(std::is_same_v<Type, bool>)
                return value.toBool();
            else if constexpr (std::is_integral_v<Type>)
                return value.toInt();
            else if constexpr(std::is_floating_point_v<Type>)
                return value.toDouble();
            else
                return value.toString();
        }
    }

    template<typename T>
    void loadSettings(T& params, const QSettings& settings)
    {
        boost::pfr::for_each_field(params, 
            [&](auto& field)
            {
                auto name = QString::fromStdString(std::string(vb::fieldName<decltype(field)>()));

                if(settings.contains(name))
                {
                    field.present = true;
                    field.value = vb::detail::convert<decltype(field.value)>(settings.value(name));
                }
            }
        );
    }

    template<typename T>
    void saveSettings(T& params, QSettings& settings)
    {
        boost::pfr::for_each_field(params, 
            [&](auto& value)
            {
                if(value.present)
                    settings.setValue(QString::fromStdString(std::string(vb::fieldName<decltype(value)>())), value.value);
            }
        );
    }
}