QT += core gui network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
TARGET = messenger_client
TEMPLATE = app

SOURCES += \
    main_ui_client.cpp \
    mainwindow.cpp \
    client.cpp

HEADERS += \
    mainwindow.h \
    client.h

FORMS += \
    mainwindow.ui

INCLUDEPATH += \
    ../common

LIBS += \
    -L../common -lcommon
