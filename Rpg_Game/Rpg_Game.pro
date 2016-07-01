#-------------------------------------------------
#
# Project created by QtCreator 2016-06-07T19:27:31
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Rpg_Game
TEMPLATE = app

CONFIG += c++11


SOURCES += main.cpp\
        gamewindow.cpp \
    map.cpp \
    character.cpp \
    entity.cpp \
    ground.cpp \
    vec2.cpp \
    window.cpp \
    file_wr.cpp \
    building.cpp \
    tile.cpp

HEADERS  += gamewindow.hpp \
    map.hpp \
    character.hpp \
    entity.hpp \
    ground.hpp \
    vec2.hpp \
    window.hpp \
    file_wr.hpp \
    building.hpp \
    tile.hpp

FORMS    += mainwindow.ui
