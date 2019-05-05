TARGET = GradColor
TEMPLATE = lib
CONFIG += plugin

DESTDIR = $${PWD}/../../../bin/plugin

INCLUDEPATH += ../../mainwindow

HEADERS += \
    gradcolor.h

SOURCES += \
    gradcolor.cpp
