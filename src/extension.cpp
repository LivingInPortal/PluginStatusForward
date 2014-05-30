#include "extension.h"
#include "Natives.h"

PluginStatusForward g_PluginStatusForward;

SMEXT_LINK(&g_PluginStatusForward);

bool PluginStatusForward::SDK_OnLoad(char *error, size_t maxlength, bool late)
{
    if(!this->ForwardInit(error, maxlength))
    {
        return false;
    }

    plsys->AddPluginsListener(this);

    sharesys->AddNatives(myself, g_RegNatives);

    return true;
}

void PluginStatusForward::SDK_OnUnload()
{
    plsys->RemovePluginsListener(this);

    this->ForwardShutdown();
}
