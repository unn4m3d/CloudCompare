#pragma once
#include <functional>
#include <QWidget>
#include <type_traits>
#include <QVector>
#include <typeinfo>
#include <functional>
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

        Field() : present(false){}
    };


    template<typename P>
    using SetterFunc = std::function<void(P&)>;

    template<typename P>
    class Setter
    {
    public:
        Setter() = default;

        Setter(const SetterFunc<const P>& setter, const SetterFunc<P>& getter) :
            m_setter(setter), m_getter(getter) {}

        void operator()(const P& p)
        {
            m_setter(p);
        }

        void get(P& p)
        {
            m_getter(p);
        }
    private:
        SetterFunc<const P> m_setter;
        SetterFunc<P> m_getter;
    };

    template<typename P>
    using SetterList = QVector<Setter<P>>;

    namespace detail
    {

        template<typename P, typename Member, typename Widget>
        static void addSetter(SetterList<P>& l, Member P::* memberPtr, Widget* w)
            requires requires(Widget w, Member a){ w.setValue(a.value); }
        {
            auto oldVal = w->value();
            l << Setter<P>(
                [memberPtr, w](const P& params)
                {
                    if((params.*memberPtr).present)
                        w->setValue((params.*memberPtr).value);
                },
                [memberPtr, w, oldVal](P& params)
                {   
                    auto val = w->value();
                    if(val != oldVal)
                    {
                        (params.*memberPtr).present = true;
                        (params.*memberPtr).value = val;
                    }
                }
            );
        }

        template<typename P, typename Member, typename Widget>
        static void addSetter(SetterList<P>& l, Member P::* memberPtr, Widget* w)
            requires requires(Widget w){ w.setChecked(true); }
        {
            auto oldVal = w->isChecked();
            l << Setter<P>(
                [memberPtr, w](const P& params)
                {
                    if((params.*memberPtr).present)
                        w->setChecked((params.*memberPtr).value);
                },
                [memberPtr, w, oldVal](P& params)
                {   
                    auto val = w->isChecked();
                    if(val != oldVal)
                    {
                        (params.*memberPtr).present = true;
                        (params.*memberPtr).value = val;
                    }
                }
            );
        }

        template<typename P, typename Member, typename Widget>
        static void addSetter(SetterList<P>& l, Member P::* memberPtr, Widget* w)
            requires requires(Widget w){ w.setCurrentIndex(0); }
        {
            auto oldVal = w->currentIndex();
            l << Setter<P>(
                [memberPtr, w](const P& params)
                {
                    if((params.*memberPtr).present)
                        w->setCurrentIndex((params.*memberPtr).value);
                },
                [memberPtr, w, oldVal](P& params)
                {   
                    auto val = w->currentIndex();
                    if(val != oldVal)
                    {
                        (params.*memberPtr).present = true;
                        (params.*memberPtr).value = val;
                    }
                }
            );
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