#include "hmsconfigurator.h"

const QSettings HmsConfigurator::m_settings{ "configuration.ini", QSettings::IniFormat };

uint HmsConfigurator::getServerPort()
{
    return m_settings.value("server/port", 8888).toUInt();
}

QString HmsConfigurator::getDatabaseName()
{
    return m_settings.value("database/name", "default.db").toString();
}

QStringList HmsConfigurator::getDatabaseSQLQueries()
{
    QStringList res;
    
    for (const QString &key : m_settings.allKeys())
        if (HmsRxs::CONFIG_DB_RX_QUERIES->match(key).hasMatch())
            res.append(m_settings.value(key, {}).toString());
    
    return res;
}
