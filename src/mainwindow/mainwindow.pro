greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

DESTDIR = $${PWD}/../../bin

HEADERS += \
    interface.h \
    mainwindow.h \
    renderwidget.h

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    renderwidget.cpp


FORMS += \
    mainwindow.ui

