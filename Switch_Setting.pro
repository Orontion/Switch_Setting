#-------------------------------------------------
#
# Project created by QtCreator 2016-01-03T13:37:05
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Switch_Setting
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    terminal.cpp \
    confinterpreter.cpp \
    confsettings.cpp

HEADERS  += mainwindow.h \
    terminal.h \
    confinterpreter.h \
    confsettings.h

FORMS    += mainwindow.ui \
    terminal.ui \
    confsettings.ui
