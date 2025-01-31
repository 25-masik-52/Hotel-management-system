#include "hmsmenuwidgetplugin.h"
#include "hmsmenuwidget.h"

#include <QtPlugin>

HmsMenuWidgetPlugin::HmsMenuWidgetPlugin(QObject* parent)
    : QObject{ parent }
{}

void HmsMenuWidgetPlugin::initialize(QDesignerFormEditorInterface*)
{
    if (m_initialized)
        return;

    m_initialized = true;
}

bool HmsMenuWidgetPlugin::isInitialized() const
{
    return m_initialized;
}

QWidget* HmsMenuWidgetPlugin::createWidget(QWidget* parent)
{
    return new HmsMenuWidget{ parent };
}

QString HmsMenuWidgetPlugin::name() const
{
    return QLatin1String{ "HmsMenuWidget" };
}

QString HmsMenuWidgetPlugin::group() const
{
    return QLatin1String{ "HmsWidgets" };
}

QIcon HmsMenuWidgetPlugin::icon() const
{
    return QIcon{ QLatin1String{ ":/hms_menu_icons/assets/icons/menu_icon.svg" } };
}

QString HmsMenuWidgetPlugin::toolTip() const
{
    return QLatin1String{ "HmsMenuWidget" };
}

QString HmsMenuWidgetPlugin::whatsThis() const
{
    return QLatin1String{ "A widget that provides custom menu for the project 'Hotel Management System'" };
}

bool HmsMenuWidgetPlugin::isContainer() const
{
    return false;
}

QString HmsMenuWidgetPlugin::domXml() const
{
    return QLatin1String{ R"(<widget class="HmsMenuWidget" name="hmsMenuWidget"></widget>)" };
}

QString HmsMenuWidgetPlugin::includeFile() const
{
    return QLatin1String{ "hmsmenuwidget.h" };
}
