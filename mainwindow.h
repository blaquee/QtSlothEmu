#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class ContextView;
class CpuModel;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_onSetContext_clicked();
protected slots:
    void onUpdateRegisterContext();
    void onContextViewFinished(int result);

private:
    Ui::MainWindow *ui;
    ContextView* cView = nullptr;
    CpuModel* emuCpuModel = nullptr;
    bool contextOpened;

    //QAction* showWindow;
};

#endif // MAINWINDOW_H
