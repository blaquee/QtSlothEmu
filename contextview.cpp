#include "contextview.h"
#include "ui_contextview.h"
#include "cpumodel.h"


ContextView::ContextView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ContextView)
{
    ui->setupUi(this);
    mCpuModel = new CpuModel(parent);

    mCpuView = new QTreeView(parent);
    mCpuView->setModel(mCpuModel);

    //insert the tree view
    ui->verticalLayout->insertWidget(0, mCpuView);
}

ContextView::~ContextView()
{
    delete ui;
}

void ContextView::on_onDoneButton_clicked()
{
    this->accept();
}
