#pragma once
#include <functional>
#include <QWidget>
#include <type_traits>
#include <QVector>
#include <typeinfo>
namespace vb
{
    // Just an empty base class to use dynamic casts
    struct SerializableHolder {
        virtual ~SerializableHolder(){}
        virtual bool isAuto() const
        {
            return false;
        }
    };

    template<typename T>
    struct Serializable : SerializableHolder
    {
        T value;

        virtual ~Serializable(){}

        virtual bool isAuto() const;
    };

    template<typename T, typename E, E Name>
    struct Field
    {
        T value;
        bool present;

        operator T&() { return value; }
        operator T() { return value; }
    };


    template<typename P>
    using Setter = std::function<void(const P&)>;

    template<typename P>
    using SetterList = QVector<Setter<P>>;

    namespace detail
    {

        template<typename P, typename Member, typename Widget>
        static void addSetter(SetterList<P>& l, Member P::* memberPtr, Widget* w)
            requires requires(Widget w, Member a){ w.setValue(a.value); }
        {
            l << [memberPtr, w](const P& params)
            {
                if((params.*memberPtr).present)
                {
                    w->setValue((params.*memberPtr).value);
                }
            };
        }

        template<typename P, typename Member, typename Widget>
        static void addSetter(SetterList<P>& l, Member P::* memberPtr, Widget* w)
            requires requires(Widget w){ w.setChecked(true); }
        {
            l << [memberPtr, w](const P& params)
            {
                if((params.*memberPtr).present)
                    w->setChecked((params.*memberPtr).value);
            };
        }

        template<typename P, typename Member, typename Widget>
        static void addSetter(SetterList<P>& l, Member P::* memberPtr, Widget* w)
            requires requires(Widget w){ w.setCurrentIndex(0); }
        {
            l << [memberPtr, w](const P& params)
            {
                if((params.*memberPtr).present)
                    w->setCurrentIndex((params.*memberPtr).value);
            };
        }

        template<typename T>
        static bool isAuto(const T& value)
        requires requires(T x){ x._auto; }
        {
            return value._auto.present && value._auto.value;
        }

        template<typename T>
        static bool isAuto(const T&)
        {
            return false;
        }
    }

    template<typename P, typename Member, typename Widget>
    void addSetter(SetterList<P>& l, Member P::* memberPtr, Widget* w)
    {
        detail::addSetter<P, Member, Widget>(l, memberPtr, w);
    }

    template<typename T>
    bool Serializable<T>::isAuto() const
    {
        return detail::isAuto(value);
    }
}