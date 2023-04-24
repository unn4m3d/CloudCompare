#pragma once
#include <QSettings>
#include <qCC_db.h>

namespace vb
{
    QCC_DB_LIB_API QSettings& getSettings();
}