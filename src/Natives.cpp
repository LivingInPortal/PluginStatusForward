#include "extension.h"

#define CHECKTYPE(type, pCtx) do { if(type <= -1 || type >= PSF_TOTALNUM) { pCtx->ThrowNativeError("Out of avaliable forward/hook types"); return 0; } } while(0)

// native bool:PSF_RegForward(PSFHookType:type, PSFCall:callback);
cell_t Native_RegFwd(IPluginContext *pCtx, const cell_t *params)
{
    PSFHookType type = (PSFHookType)params[1];
    funcid_t FuncID = static_cast<funcid_t>(params[2]);

    CHECKTYPE(type, pCtx);

    return g_PSFpForwards[type]->AddFunction(pCtx, FuncID);
}

// native bool:PSF_DelForward(PSFHookType:type, PSFCall:callback);
cell_t Native_DelFwd(IPluginContext *pCtx, const cell_t *params)
{
    PSFHookType type = (PSFHookType)params[1];
    funcid_t FuncID = static_cast<funcid_t>(params[2]);

    CHECKTYPE(type, pCtx);

    return g_PSFpForwards[type]->RemoveFunction(pCtx, FuncID);
}

// native PSF_DelAllForwardInType(PSFHookType:type);
cell_t Native_DelFwdAll(IPluginContext *pCtx, const cell_t *params)
{
    PSFHookType type = (PSFHookType)params[1];

    CHECKTYPE(type, pCtx);

    IPlugin *plugin = plsys->FindPluginByContext(pCtx->GetContext());
    return g_PSFpForwards[type]->RemoveFunctionsOfPlugin(plugin);
}
