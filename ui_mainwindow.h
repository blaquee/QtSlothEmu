/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionContext_Editor;
    QAction *actionContext_Editor_Menu;
    QAction *actionMapped_Mem_View;
    QAction *actionConfigure;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QListView *listViewDisasm;
    QTableView *tableViewContext;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *onSetContext;
    QPushButton *onStepButton;
    QPushButton *onEmulateButton;
    QMenuBar *menuBar;
    QMenu *menu_Setup;
    QMenu *menuView;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(618, 463);
        actionContext_Editor = new QAction(MainWindow);
        actionContext_Editor->setObjectName(QStringLiteral("actionContext_Editor"));
        actionContext_Editor_Menu = new QAction(MainWindow);
        actionContext_Editor_Menu->setObjectName(QStringLiteral("actionContext_Editor_Menu"));
        actionMapped_Mem_View = new QAction(MainWindow);
        actionMapped_Mem_View->setObjectName(QStringLiteral("actionMapped_Mem_View"));
        actionConfigure = new QAction(MainWindow);
        actionConfigure->setObjectName(QStringLiteral("actionConfigure"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        listViewDisasm = new QListView(centralWidget);
        listViewDisasm->setObjectName(QStringLiteral("listViewDisasm"));

        horizontalLayout_2->addWidget(listViewDisasm);

        tableViewContext = new QTableView(centralWidget);
        tableViewContext->setObjectName(QStringLiteral("tableViewContext"));

        horizontalLayout_2->addWidget(tableViewContext);


        verticalLayout_2->addLayout(horizontalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        onSetContext = new QPushButton(centralWidget);
        onSetContext->setObjectName(QStringLiteral("onSetContext"));

        horizontalLayout->addWidget(onSetContext);

        onStepButton = new QPushButton(centralWidget);
        onStepButton->setObjectName(QStringLiteral("onStepButton"));

        horizontalLayout->addWidget(onStepButton);

        onEmulateButton = new QPushButton(centralWidget);
        onEmulateButton->setObjectName(QStringLiteral("onEmulateButton"));

        horizontalLayout->addWidget(onEmulateButton);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 618, 26));
        menu_Setup = new QMenu(menuBar);
        menu_Setup->setObjectName(QStringLiteral("menu_Setup"));
        menuView = new QMenu(menuBar);
        menuView->setObjectName(QStringLiteral("menuView"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu_Setup->menuAction());
        menuBar->addAction(menuView->menuAction());
        menu_Setup->addAction(actionConfigure);
        menuView->addAction(actionContext_Editor_Menu);
        menuView->addAction(actionMapped_Mem_View);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionContext_Editor->setText(QApplication::translate("MainWindow", "Context Editor", 0));
        actionContext_Editor_Menu->setText(QApplication::translate("MainWindow", "Context Editor", 0));
        actionMapped_Mem_View->setText(QApplication::translate("MainWindow", "Mapped Mem View", 0));
        actionConfigure->setText(QApplication::translate("MainWindow", "Configure", 0));
        actionConfigure->setShortcut(QApplication::translate("MainWindow", "Ctrl+C", 0));
        onSetContext->setText(QApplication::translate("MainWindow", "Set Context", 0));
        onStepButton->setText(QApplication::translate("MainWindow", "Step", 0));
        onEmulateButton->setText(QApplication::translate("MainWindow", "Emulate", 0));
        menu_Setup->setTitle(QApplication::translate("MainWindow", " Setup", 0));
        menuView->setTitle(QApplication::translate("MainWindow", "Views", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
