#include <vb/settings.hpp>

namespace vb
{
    static QSettings settings(qEnvironmentVariable("CC_SETTINGS_FILE", "/app/settings/cc_settings.ini"), QSettings::IniFormat);

    extern QSettings& getSettings()
    { 
        return settings; 
    }
}