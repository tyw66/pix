#-------------------------------------------------
# Project created by QtCreator 2019-05-05T14:23:41
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


QMAKE_CXXFLAGS += -fopenmp
LIBS += -lgomp -lpthread
LIBS += -lgomp -lpthread

INCLUDEPATH += $${PWD}/../../libs/common
LIBS += -L$${PWD}/../../../bin -lcommon
