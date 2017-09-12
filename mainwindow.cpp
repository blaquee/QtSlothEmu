#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_onSetContext_clicked()
{
    if(cView || contextOpened)
        return;
    cView = new ContextView();
    cView->show();
    contextOpened = true;
}
