QT+= serialbus serialport widgets

TEMPLATE      = lib
CONFIG       += plugin
TARGET        = $$qtLibraryTarget(modbusMaster)
DESTDIR       = ../../Drivers

INCLUDEPATH += $$PWD\

CONFIG+= C++11

HEADERS += \
    $$PWD/modbusmasterprotocoldriver.h \
    $$PWD/modbusmasterprotocoldriverui.h \
    $$PWD/modbusmasterparametersmodel.h \
    modbusmasterparametersdelegate.h

SOURCES += \
    $$PWD/modbusmasterprotocoldriver.cpp \
    $$PWD/modbusmasterprotocoldriverui.cpp \
    $$PWD/modbusmasterparametersmodel.cpp

FORMS += \
    $$PWD/modbusmasterprotocoldriverui.ui

#interface:
include(../../Interface/Interface.pri)

#base library: load & save to xml or json
include(../../../lib/loadSaveProcessor/src/loadsaveProcessor.pri)
