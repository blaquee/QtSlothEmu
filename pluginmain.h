#ifndef _PLUGINMAIN_H
#define _PLUGINMAIN_H

#include <windows.h>
#include "pluginsdk\_plugins.h"

namespace Plugin
{
    extern int handle;
    extern HWND hwndDlg;
    extern int hMenu;
    extern int hMenuDisasm;
    extern int hMenuDump;
    extern int hMenuStack;
} //Plugin

#endif //_PLUGINMAIN_H