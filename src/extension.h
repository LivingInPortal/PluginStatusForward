#ifndef _INCLUDE_SOURCEMOD_EXTENSION_PROPER_H_
#define _INCLUDE_SOURCEMOD_EXTENSION_PROPER_H_

#include "smsdk_ext.h"


class PluginStatusForward : public SDKExtension, public IPluginsListener
{
public:     // SDKExtension
    virtual bool SDK_OnLoad(char *error, size_t maxlength, bool late);
    virtual void SDK_OnUnload();

public:		// IPluginListener
    void OnPluginCreated(IPlugin *plugin);
    void OnPluginLoaded(IPlugin *plugin);
    void OnPluginUnloaded(IPlugin *plugin);
    void OnPluginPauseChange(IPlugin *plugin, bool paused);
    void OnPluginDestroyed(IPlugin *plugin);

public:     // Forward_INIT
    bool ForwardInit(char* error, size_t maxlength);
    void ForwardShutdown();
};

enum PSFHookType
{
    PSF_OnPluginCreated,
    PSF_OnPluginLoaded,
    PSF_OnPluginPauseChange,
    PSF_OnPluginUnloaded,
    PSF_OnPluginDestroyed,
    /********************/
    PSF_TOTALNUM
};

extern IChangeableForward* g_PSFpForwards[PSF_TOTALNUM];
extern PluginStatusForward g_PluginStatusForward;

#endif // _INCLUDE_SOURCEMOD_EXTENSION_PROPER_H_
