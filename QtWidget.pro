#-------------------------------------------------
#
# Project created by QtCreator 2017-09-11T00:12:28
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtWidget
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    contextview.cpp \
    cpumodel.cpp

HEADERS  += mainwindow.h \
    contextview.h \
    cpumodel.h

FORMS    += mainwindow.ui \
    contextview.ui
