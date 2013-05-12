#-------------------------------------------------
#
# Project created by QtCreator 2012-07-28T22:21:20
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LevelCreatorQt_v2
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    renderer.cpp

HEADERS  += mainwindow.hpp \
    renderer.hpp

FORMS    += mainwindow.ui

RESOURCES += \
    resources.qrc
