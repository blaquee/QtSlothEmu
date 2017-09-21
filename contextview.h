#ifndef CONTEXTVIEW_H
#define CONTEXTVIEW_H

#include <QDialog>
#include <QTreeView>


class CpuModel;

namespace Ui {
class ContextView;
}

class ContextView : public QDialog
{
    Q_OBJECT

public:
    explicit ContextView(QWidget *parent = 0);
    ~ContextView();

private slots:
    void on_onDoneButton_clicked();

    void on_onUseCurContext_clicked();

private:
    Ui::ContextView *ui;
    CpuModel* mCpuModel;
    QTreeView *mCpuView;

};

#endif // CONTEXTVIEW_H
