#if defined _PSF_included
 #endinput
#endif
#define _PSF_included



enum PSFHookType
{
        PSF_OnPluginCreated,
        PSF_OnPluginLoaded,
        PSF_OnPluginPauseChange,
        PSF_OnPluginUnloaded,
        PSF_OnPluginDestroyed
};

funcenum PSFCall
{
        public(Handle:plugin),
        public(Handle:plugin, bool:paused)
};

native bool:PSF_RegForward(PSFHookType:type, PSFCall:callback);
native bool:PSF_DelForward(PSFHookType:type, PSFCall:callback);
native PSF_DelAllForwardInType(PSFHookType:type);
stock PSF_DelAllForward() {
        for(new PSFHookType:i = PSFHookType:0; i < PSFHookType; i++) {
                PSF_DelAllForwardInType(i);
        }
}


public Extension:__ext_sdkhooks =
{
        name = "PSF",
        file = "PluginStatusForward.ext",
#if defined AUTOLOAD_EXTENSIONS
        autoload = 1,
#else
        autoload = 0,
#endif
#if defined REQUIRE_EXTENSIONS
        required = 1,
#else
        required = 0,
#endif
};
