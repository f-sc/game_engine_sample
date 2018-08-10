#-------------------------------------------------
#
# Project created by QtCreator 2018-07-28T15:42:19
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = game_engine
TEMPLATE = app


SOURCES += main.cpp\
        main_window.cpp \
    map_elements.cpp \
    error_manager.cpp \
    project_manager.cpp \
    filesystemod.cpp

HEADERS  += main_window.h \
    map_elements.h \
    error_manager.h \
    project_manager.h \
    filesystemod.h

FORMS    += main_window.ui

QMAKE_EXTRA_TARGETS += before_build makefilehook

makefilehook.target = $(MAKEFILE)
makefilehook.depends = .beforebuild

PRE_TARGETDEPS += .beforebuild

before_build.target = .beforebuild
before_build.depends = FORCE
before_build.commands = chcp 1251
