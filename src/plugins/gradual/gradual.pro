TARGET = gradual
TEMPLATE = lib
CONFIG += plugin

DESTDIR = $${PWD}/../../../bin/plugin
INCLUDEPATH += ../../mainwindow

HEADERS += \
    gradual.h

SOURCES += \
    gradual.cpp
