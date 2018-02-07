QT+= network widgets

TEMPLATE      = lib
CONFIG       += plugin
TARGET        = $$qtLibraryTarget(multicastProtocol)
DESTDIR       = ../../Drivers

CONFIG += c++11

INCLUDEPATH += $$PWD\

HEADERS += \
    $$PWD/multicastprotocoldriver.h \
    $$PWD/multicastprotocoldriverui.h
SOURCES += \
    $$PWD/multicastprotocoldriver.cpp \
    $$PWD/multicastprotocoldriverui.cpp
FORMS += \
    $$PWD/multicastprotocoldriverui.ui

#interface:
include(../../Interface/Interface.pri)

#base library: load & save to xml or json
include(../../../lib/loadSaveProcessor/src/loadsaveProcessor.pri)
