#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "contextview.h"
#include "ui_contextview.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Create UIs
    cView = new ContextView(this);

    //connect signals and slots
    //connect();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_onSetContext_clicked()
{
    cView->show();

    QEventLoop event;
    connect(this, SIGNAL(destroyed()), &event, SLOT(quit()));
    event.exec();

    //QMessageBox
}

void MainWindow::onUpdateRegisterContext()
{

}
