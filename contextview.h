#ifndef CONTEXTVIEW_H
#define CONTEXTVIEW_H

#include <QDialog>

namespace Ui {
class ContextView;
}

class ContextView : public QDialog
{
    Q_OBJECT

public:
    explicit ContextView(QWidget *parent = 0);
    ~ContextView();

private:
    Ui::ContextView *ui;
};

#endif // CONTEXTVIEW_H
