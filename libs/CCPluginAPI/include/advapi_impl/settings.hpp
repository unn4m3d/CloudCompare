#pragma once

namespace advapi
{
    struct CCPLUGIN_LIB_API SubsampleSettings
    {
        double value;
        unsigned char method;
        bool automatic;
        
    };
}

Q_DECLARE_METATYPE(advapi::SubsampleSettings);