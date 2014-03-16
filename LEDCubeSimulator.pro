#-------------------------------------------------
#
# Project created by QtCreator 2014-02-24T09:33:03
#
#-------------------------------------------------

QT       += core gui opengl network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LEDCubeSimulator
TEMPLATE = app

CONFIG += debug_and_release

SOURCES += main.cpp \
    gl/ledcubeglwidget.cpp \
    gl/shapes.cpp \
    types/ledcubestate.cpp \
    network/communicator.cpp \
    gui/mainwindow.cpp


HEADERS  += \
    gl/ledcubeglwidget.h \
    gl/shapes.h \
    types/ledcubestate.h \
    network/communicator.h \
    gui/mainwindow.h

FORMS += \
    gui/mainwindow.ui
