QT+= network widgets

TEMPLATE      = lib
CONFIG       += plugin
TARGET        = $$qtLibraryTarget(UdpDatabaseProtocol)
DESTDIR       = ../../Drivers

CONFIG += c++11

INCLUDEPATH += $$PWD\

HEADERS += \
    $$PWD/udpdatabaseprotocoldriver.h \
    $$PWD/udpdatabaseprotocoldriverui.h
SOURCES += \
    $$PWD/udpdatabaseprotocoldriver.cpp \
    $$PWD/udpdatabaseprotocoldriverui.cpp
FORMS += \
    $$PWD/udpdatabaseprotocoldriverui.ui

#interface:
include(../../Interface/Interface.pri)

#base library: load & save to xml or json
include(../../../lib/loadSaveProcessor/src/loadsaveProcessor.pri)
