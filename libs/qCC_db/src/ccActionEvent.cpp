#include "ccActionEvent.h"

ccActionEvent::ccActionEvent(ccActionEvent::Kind k, const QString& aid, const QString& desc) :
    QEvent(static_cast<QEvent::Type>(getType())),
    m_kind(k),
    m_actionId(aid),
    m_description(desc)
{}

int ccActionEvent::getType()
{
    static int type = QEvent::registerEventType();
    return type;
}

ccActionEvent::Kind ccActionEvent::getKind() const
{
    return m_kind;
}

QString ccActionEvent::getActionId() const
{
    return m_actionId;
}

QString ccActionEvent::getDescription() const
{
    return m_description;
}