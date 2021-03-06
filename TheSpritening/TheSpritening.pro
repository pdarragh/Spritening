#-------------------------------------------------
#
# Project created by QtCreator 2015-11-01T13:13:42
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

TARGET = TheSpritening
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    cell.cpp \
    canvas.cpp \
    preview.cpp \
    dialog.cpp \
    load.cpp \
    sprite.cpp \
    frame.cpp \
    controller.cpp

HEADERS  += mainwindow.h \
    cell.h \
    canvas.h \
    preview.h \
    dialog.h \
    load.h \
    sprite.h \
    frame.h \
    controller.h

FORMS    += mainwindow.ui \
    preview.ui \
    dialog.ui \
    load.ui

RESOURCES += \
    resources.qrc
