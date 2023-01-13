#pragma once
#include <QEvent>
#include "qCC_db.h"
#include <QString>

class QCC_DB_LIB_API ccActionEvent : public QEvent
{
public:
    enum Kind{ TRIGGERED, FINISHED, CANCELLED };

    ccActionEvent(Kind k, const QString& actionId, const QString& description);
    virtual ~ccActionEvent(){}

    QString getActionId() const;
    QString getDescription() const;
    Kind getKind() const;

    static int getType();

private:
    Kind m_kind;
    QString m_actionId, m_description;
};