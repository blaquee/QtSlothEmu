#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "contextview.h"
#include "ui_contextview.h"
#include "cpumodel.h"

#include "pluginmain.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Create UIs
    cView = new ContextView(this);
    emuCpuModel = new CpuModel(parent);
    ui->tableViewContext->setModel(emuCpuModel);

    //connect signals and slots
    connect(cView, SIGNAL(finished(int)), this, SLOT(onContextViewFinished(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete emuCpuModel;
    delete cView;
}

void MainWindow::on_onSetContext_clicked()
{
    cView->exec();
}

void MainWindow::onUpdateRegisterContext()
{

}

void MainWindow::onContextViewFinished(int result)
{
    // Here we can update any Emu reg Data
    if(result == QDialog::Accepted)
    {
        GuiAddLogMessage("Context View Accepted Slot");
    }
}
