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
    null_entity.cpp \
    vec2.cpp \
    window.cpp \
    file_wr.cpp

HEADERS  += gamewindow.hpp \
    map.hpp \
    character.hpp \
    entity.hpp \
    null_entity.hpp \
    vec2.hpp \
    window.hpp \
    file_wr.hpp

FORMS    += mainwindow.ui
