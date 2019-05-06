TARGET = Light
TEMPLATE = lib
CONFIG += plugin

DESTDIR = $${PWD}/../../../bin/plugin

INCLUDEPATH += ../../mainwindow

HEADERS += \
    light.h

SOURCES += \
    light.cpp



QMAKE_CXXFLAGS += -fopenmp
LIBS += -lgomp -lpthread
LIBS += -lgomp -lpthread

INCLUDEPATH += $${PWD}/../../libs/common
LIBS += -L$${PWD}/../../../bin -lcommon
