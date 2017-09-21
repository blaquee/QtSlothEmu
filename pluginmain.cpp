#include "pluginmain.h"
#include "qemuplugin.h"

#define plugin_name "SlothEmu"
#define plugin_version 1

int Plugin::handle;
HWND Plugin::hwndDlg;
int Plugin::hMenu;
int Plugin::hMenuDisasm;
int Plugin::hMenuDump;
int Plugin::hMenuStack;
bool emuShown;

enum MenuEntries
{
    MENU_SHOW_EMU = 1001
};



extern "C" __declspec(dllexport) bool pluginit(PLUG_INITSTRUCT* initStruct)
{
    initStruct->pluginVersion = plugin_version;
    initStruct->sdkVersion = PLUG_SDKVERSION;
    strcpy_s(initStruct->pluginName, plugin_name);

    Plugin::handle = initStruct->pluginHandle;
    QEmuPlugin::Init();
    return true;
}

extern "C" __declspec(dllexport) void plugsetup(PLUG_SETUPSTRUCT* setupStruct)
{
    Plugin::hwndDlg = setupStruct->hwndDlg;
    Plugin::hMenu = setupStruct->hMenu;
    Plugin::hMenuDisasm = setupStruct->hMenuDisasm;
    Plugin::hMenuDump = setupStruct->hMenuDump;
    Plugin::hMenuStack = setupStruct->hMenuStack;
    auto rMenu = _plugin_menuadd(Plugin::hMenu, plugin_name);
    _plugin_menuaddentry(Plugin::hMenu, MENU_SHOW_EMU, "Launch SlothEmu");

    GuiExecuteOnGuiThread(QEmuPlugin::Setup);
}

extern "C" __declspec(dllexport) bool plugstop()
{
    GuiExecuteOnGuiThread(QEmuPlugin::Stop);
    return true;
}

extern "C" __declspec(dllexport) void CBMENUENTRY(CBTYPE cbType, PLUG_CB_MENUENTRY* info)
{
    UNREFERENCED_PARAMETER(cbType);
    switch(info->hEntry)
    {
    case MENU_SHOW_EMU:
        GuiAddLogMessage("Pressed Menu button");
    }
}
