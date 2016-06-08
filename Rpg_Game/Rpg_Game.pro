#-------------------------------------------------
#
# Project created by QtCreator 2016-06-07T19:27:31
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Rpg_Game
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    map.cpp \
    character.cpp \
    tile.cpp

HEADERS  += mainwindow.hpp \
    map.hpp \
    character.hpp \
    tile.hpp

FORMS    += mainwindow.ui
