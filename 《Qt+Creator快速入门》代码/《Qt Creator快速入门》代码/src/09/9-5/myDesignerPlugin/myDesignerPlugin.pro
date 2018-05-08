CONFIG      += designer plugin debug_and_release
TARGET      = $$qtLibraryTarget(mydesignerpluginplugin)
TEMPLATE    = lib

HEADERS     = mydesignerpluginplugin.h
SOURCES     = mydesignerpluginplugin.cpp
RESOURCES   = icons.qrc
LIBS        += -L. 

target.path = $$[QT_INSTALL_PLUGINS]/designer
INSTALLS    += target

include(mydesignerplugin.pri)
