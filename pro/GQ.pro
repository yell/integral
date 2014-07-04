#-------------------------------------------------
#
# Project created by QtCreator 2014-04-30T21:24:46
#
#-------------------------------------------------

QT  += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GQ
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

RESOURCES += \
    MyResources.qrc

win32:RC_ICONS += icon.ico

