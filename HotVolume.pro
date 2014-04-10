#-------------------------------------------------
#
# Project created by QtCreator 2014-04-10T16:19:53
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = HotVolume
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp

HEADERS  += widget.h

unix|win32: LIBS += -L$$PWD/BASS/ -lbass

INCLUDEPATH += $$PWD/BASS
DEPENDPATH += $$PWD/BASS
