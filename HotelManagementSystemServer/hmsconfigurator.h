#pragma once

#include "hmsconstants.h"
#include <QString>
#include <QSettings>

class HmsConfigurator
{
public:
    /// Server
    static uint getServerPort();
    
    /// Database
    static QString getDatabaseName();
    static QStringList getDatabaseSQLQueries();
    
private:
    static const QSettings m_settings;
};
