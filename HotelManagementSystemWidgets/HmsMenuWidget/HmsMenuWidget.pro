CONFIG      += plugin debug_and_release
TARGET      = $$qtLibraryTarget(HmsMenuWidgetPlugin)
TEMPLATE    = lib

HEADERS     = hmsmenuwidgetplugin.h
SOURCES     = hmsmenuwidgetplugin.cpp
RESOURCES   = \
    hmsmenuwidgetresources.qrc
LIBS        += -L. 

QT += designer

target.path = $$[QT_INSTALL_PLUGINS]/designer
INSTALLS    += target

include(hmsmenuwidget.pri)
