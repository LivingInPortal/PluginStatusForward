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

functag PSFCall public(Handle:plugin);

native bool:PSF_RegForward(PSFHookType:type, PSFCall:callback);
native bool:PSF_DelForward(PSFHookType:type, PSFCall:callback);
native PSF_DelAllForwardInType(PSFHookType:type);


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