#ifndef NATIVES_H_INCLUDED
#define NATIVES_H_INCLUDED

cell_t Native_RegFwd(IPluginContext *pContext, const cell_t *params);
cell_t Native_DelFwd(IPluginContext *pContext, const cell_t *params);
cell_t Native_DelFwdAll(IPluginContext *pContext, const cell_t *params);

const sp_nativeinfo_t g_RegNatives[] =
{
    {"PSF_RegForward", Native_RegFwd},
    {"PSF_DelForward", Native_DelFwd},
    {"PSF_DelAllForwardInType", Native_DelFwdAll},
    {NULL, NULL},
};


#endif // NATIVES_H_INCLUDED
