#include <sourcemod>
#include <PSF>

public Plugin:myinfo = {
	name = "PSF Test",
	author = "Foobar",
	description = "",
	version = "0.0",
	url = ""
};

public OnPluginStart() {
	RegServerCmd("psftest_load", PSFTestCB_Load);
	RegServerCmd("psftest_unload", PSFTestCB_Unload);
	RegServerCmd("psftest_unloadall", PSFTestCB_UnloadAll);
	RegServerCmd("psftest_error", PSFTestCB_Error);
}

public Action:PSFTestCB_Load(args) {
	Load();
}

public Action:PSFTestCB_Unload(args) {
	Unload();
}

public Action:PSFTestCB_UnloadAll(args) {
	UnloadAll();
}

public Action:PSFTestCB_Error(args) {
	Error();
}

Load() {
	PSF_RegForward(PSF_OnPluginCreated, OnPluginCreated);
	PSF_RegForward(PSF_OnPluginLoaded, OnPluginLoaded);
	PSF_RegForward(PSF_OnPluginPauseChange, OnPluginPauseChanged);
	PSF_RegForward(PSF_OnPluginUnloaded, OnPluginUnloaded);
	PSF_RegForward(PSF_OnPluginDestroyed, OnPluginDestroyed);
}

Unload() {
	// Intended Detach Partially
	PSF_DelForward(PSF_OnPluginLoaded, OnPluginLoaded);
	PSF_DelForward(PSF_OnPluginDestroyed, OnPluginDestroyed);
}

UnloadAll() {
	PSF_DelAllForward();
}

Error() {
	PSF_RegForward(PSFHookType:6, OnPluginLoaded);
}

public OnPluginCreated(Handle:plugin) {
	decl String:filename[101];
	GetPluginFilename(plugin, filename, sizeof(filename));
	PrintToServer("%s Handle:%x PluginCreated", filename, plugin);
}

public OnPluginLoaded(Handle:plugin) {
	decl String:filename[101];
	GetPluginFilename(plugin, filename, sizeof(filename));
	PrintToServer("%s Handle:%x PluginLoaded", filename, plugin);
}

public OnPluginPauseChanged(Handle:plugin, bool:paused) {
	decl String:filename[101];
	GetPluginFilename(plugin, filename, sizeof(filename));
	PrintToServer("%s Handle:%x PluginPauseChange paused:%d", filename, plugin, paused);
}

public OnPluginUnloaded(Handle:plugin) {
	decl String:filename[101];
	GetPluginFilename(plugin, filename, sizeof(filename));
	PrintToServer("%s Handle:%x PluginUnloaded", filename, plugin);
}

public OnPluginDestroyed(Handle:plugin) {
	decl String:filename[101];
	GetPluginFilename(plugin, filename, sizeof(filename));
	PrintToServer("%s Handle:%x PluginDestroyed", filename, plugin);
}
