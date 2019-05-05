greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

HEADERS += \
    interface.h \
    mainwindow.h \
    renderwidget.h

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    renderwidget.cpp

DESTDIR = $${PWD}/../../bin

FORMS += \
    mainwindow.ui

