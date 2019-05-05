#-------------------------------------------------
#
# Project created by QtCreator 2019-05-05T14:23:41
#
#-------------------------------------------------
TARGET = FunnyFace
TEMPLATE = lib
CONFIG += plugin

DESTDIR = $${PWD}/../../../bin/plugin
INCLUDEPATH += ../../mainwindow

SOURCES += \
    funnyfaceplugin.cpp

HEADERS += \
    funnyfaceplugin.h

INCLUDEPATH += ../../libs/common
LIBS += -L../../../bin -lcommon
