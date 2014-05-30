#include "extension.h"

#define GET_PLUGIN_HANDLE(handle)       Handle_t handle = plugin->GetMyHandle()
#define IGNORE_EXECUTE(INDEX)           g_PSFpForwards[INDEX]->Execute(NULL)


void PluginStatusForward::OnPluginCreated(IPlugin *plugin)
{
    GET_PLUGIN_HANDLE(handle);

    g_PSFpForwards[PSF_OnPluginCreated]->PushCell(handle);
    IGNORE_EXECUTE(PSF_OnPluginCreated);
}

void PluginStatusForward::OnPluginLoaded(IPlugin *plugin)
{
    GET_PLUGIN_HANDLE(handle);

    g_PSFpForwards[PSF_OnPluginLoaded]->PushCell(handle);
    IGNORE_EXECUTE(PSF_OnPluginLoaded);
}

void PluginStatusForward::OnPluginPauseChange(IPlugin *plugin, bool paused)
{
    GET_PLUGIN_HANDLE(handle);

    g_PSFpForwards[PSF_OnPluginPauseChange]->PushCell(handle);
    g_PSFpForwards[PSF_OnPluginPauseChange]->PushCell(paused);
    IGNORE_EXECUTE(PSF_OnPluginPauseChange);
}

void PluginStatusForward::OnPluginUnloaded(IPlugin *plugin)
{
    GET_PLUGIN_HANDLE(handle);

    g_PSFpForwards[PSF_OnPluginUnloaded]->PushCell(handle);
    IGNORE_EXECUTE(PSF_OnPluginUnloaded);
}

void PluginStatusForward::OnPluginDestroyed(IPlugin *plugin)
{
    GET_PLUGIN_HANDLE(handle);

    g_PSFpForwards[PSF_OnPluginDestroyed]->PushCell(handle);
    IGNORE_EXECUTE(PSF_OnPluginDestroyed);
}
