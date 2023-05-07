QT += core network
TARGET = messenger_server
TEMPLATE = app

SOURCES += \
    main_server.cpp \
    server.cpp

HEADERS += \
    server.hpp

INCLUDEPATH += \
    ../common

LIBS += \
    -L../common -lcommon
