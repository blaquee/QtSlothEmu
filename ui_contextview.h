/********************************************************************************
** Form generated from reading UI file 'contextview.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTEXTVIEW_H
#define UI_CONTEXTVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ContextView
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *onUseCurContext;
    QPushButton *onDoneButton;

    void setupUi(QDialog *ContextView)
    {
        if (ContextView->objectName().isEmpty())
            ContextView->setObjectName(QStringLiteral("ContextView"));
        ContextView->setWindowModality(Qt::WindowModal);
        ContextView->resize(400, 300);
        verticalLayout_2 = new QVBoxLayout(ContextView);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        onUseCurContext = new QPushButton(ContextView);
        onUseCurContext->setObjectName(QStringLiteral("onUseCurContext"));

        horizontalLayout->addWidget(onUseCurContext);

        onDoneButton = new QPushButton(ContextView);
        onDoneButton->setObjectName(QStringLiteral("onDoneButton"));

        horizontalLayout->addWidget(onDoneButton);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(ContextView);

        QMetaObject::connectSlotsByName(ContextView);
    } // setupUi

    void retranslateUi(QDialog *ContextView)
    {
        ContextView->setWindowTitle(QApplication::translate("ContextView", "Context Editor", 0));
        onUseCurContext->setText(QApplication::translate("ContextView", "Use Current Context", 0));
        onDoneButton->setText(QApplication::translate("ContextView", "Done", 0));
    } // retranslateUi

};

namespace Ui {
    class ContextView: public Ui_ContextView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTEXTVIEW_H
