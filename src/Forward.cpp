#include "extension.h"

IChangeableForward* g_PSFpForwards[PSF_TOTALNUM];

#define CREATE_UNMANAGED_FORWARD(name, et, num_params, types, ...)  forwards->CreateForwardEx(name, et, num_params, types, ##__VA_ARGS__)
#define PRINT_ERROR(fmt, ...)                                       snprintf(error, maxlength, fmt, ##__VA_ARGS__)
bool PluginStatusForward::ForwardInit(char* error, size_t maxlength)
{
    g_PSFpForwards[PSF_OnPluginCreated] = CREATE_UNMANAGED_FORWARD(NULL, ET_Ignore, 1, NULL, Param_Cell);
    if(g_PSFpForwards[PSF_OnPluginCreated] == NULL)
    {
        PRINT_ERROR("Could not create \"OnPluginCreated\" forward");
        return false;
    }

    g_PSFpForwards[PSF_OnPluginLoaded] = CREATE_UNMANAGED_FORWARD(NULL, ET_Ignore, 1, NULL, Param_Cell);
    if(g_PSFpForwards[PSF_OnPluginLoaded] == NULL)
    {
        PRINT_ERROR("Could not create \"OnPluginLoaded\" forward");
        return false;
    }

    g_PSFpForwards[PSF_OnPluginPauseChange] = CREATE_UNMANAGED_FORWARD(NULL, ET_Ignore, 2, NULL, Param_Cell, Param_Cell);
    if(g_PSFpForwards[PSF_OnPluginPauseChange] == NULL)
    {
        PRINT_ERROR("Could not create \"OnPluginPauseChange\" forward");
        return false;
    }

    g_PSFpForwards[PSF_OnPluginUnloaded] = CREATE_UNMANAGED_FORWARD(NULL, ET_Ignore, 1, NULL, Param_Cell);
    if(g_PSFpForwards[PSF_OnPluginUnloaded] == NULL)
    {
        PRINT_ERROR("Could not create \"OnPluginUnloaded\" forward");
        return false;
    }

    g_PSFpForwards[PSF_OnPluginDestroyed] = CREATE_UNMANAGED_FORWARD(NULL, ET_Ignore, 1, NULL, Param_Cell);
    if(g_PSFpForwards[PSF_OnPluginDestroyed] == NULL)
    {
        PRINT_ERROR("Could not create \"OnPluginDestroyed\" forward");
        return false;
    }

    return true;
}

void PluginStatusForward::ForwardShutdown()
{
    for(int i = 0; i < PSF_TOTALNUM; i++)
    {
        forwards->ReleaseForward(g_PSFpForwards[i]);
    }
}
