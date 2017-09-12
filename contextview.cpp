#include "contextview.h"
#include "ui_contextview.h"

ContextView::ContextView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ContextView)
{
    ui->setupUi(this);
}

ContextView::~ContextView()
{
    delete ui;
}

void ContextView::on_doneButton_clicked()
{
    this->accept();
}
