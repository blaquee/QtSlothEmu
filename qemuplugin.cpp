#include "qemuplugin.h"
#include "contextview.h"
#include "mainwindow.h"
#include "defines.h"
#include "pluginmain.h"

static MainWindow* EmuMainWindow;

static QWidget* getParent()
{
    return QWidget::find((WId)Plugin::hwndDlg);
}

void QEmuPlugin::Init()
{
    GuiAddLogMessage("[SLOTHEMU] SlothEmu Started");
}

void QEmuPlugin::Setup()
{
    if(!EmuMainWindow)
    {
        QWidget* parent = getParent();
        EmuMainWindow = new MainWindow(parent);

        EmuMainWindow->show();
    }
    else
    {
        EmuMainWindow->show();
    }
}

void QEmuPlugin::Stop()
{
    if(EmuMainWindow)
        delete EmuMainWindow;
}
