#include <vb/field_misc.hpp>

namespace vb
{
    QSettings settings(qEnvironmentVariable("CC_SETTINGS_FILE", "/app/settings/cc_settings.ini"), QSettings::IniFormat);
}