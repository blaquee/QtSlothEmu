#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class ContextView;

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

private:
    Ui::MainWindow *ui;
    ContextView* cView = nullptr;
    bool contextOpened;
};

#endif // MAINWINDOW_H
