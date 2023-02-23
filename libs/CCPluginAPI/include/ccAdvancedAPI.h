#pragma once
#include "CCPluginAPI.h"
#include <QObject>
#include <QVariant>
#include "ccAdvancedAPISigDecl.h"
#include <map>
#include <iostream>
#include <memory>
#include "vb/field.hpp"

class ccHObject;
class ccPluginUIManager;
class ccPluginInterface;

class CCPLUGIN_LIB_API ccAdvancedAPI : public ccAdvancedAPISigDecl
{
    Q_OBJECT
public:
    ccAdvancedAPI(QObject* parent = nullptr);

    void initialize();
    virtual ~ccAdvancedAPI();

    void triggerActionCompleted(QString id, QVariant results);
    void triggerActionFailed(QString id, QString reason);
    void triggerActionCanceled(QString id);

    void setParams(const QString&, std::shared_ptr<vb::SerializableHolder>);
    std::shared_ptr<vb::SerializableHolder> getParams(const QString&, bool = true);

    template<typename T>
    std::shared_ptr<vb::Serializable<T>> params(const QString& a, bool del = false)
    {
        return std::dynamic_pointer_cast<vb::Serializable<T>>(getParams(a, del));
    }

    void triggerActionFinished(const QString& s)
    {
        Q_EMIT actionFinished(s);
    }

Q_SIGNALS:
    void initialized();

    void actionCompleted(QString id, QVariant results);
    void actionFailed(QString id, QString reason);
    void actionCanceled(QString id);
    
    void addedToDB(ccHObject*);

    void actionTriggered(QString);
    void actionFinished(QString);

public Q_SLOTS:
    void launchAction(QString id, QVariant settings);

    void notImplemented(QString id);

private:
    
    QMap<QString, std::shared_ptr<vb::SerializableHolder>> m_params;
    
};