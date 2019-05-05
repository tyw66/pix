TARGET = Circle
TEMPLATE = lib
CONFIG += plugin

DESTDIR = $${PWD}/../../../bin/plugin
INCLUDEPATH += ../../mainwindow

HEADERS += \
    circle.h

SOURCES += \
    circle.cpp
