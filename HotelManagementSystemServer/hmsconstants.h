#pragma once

#include <QString>
#include <QRegularExpression>

namespace HmsRxs
{
Q_GLOBAL_STATIC(QRegularExpression, CONFIG_DB_RX_QUERIES, { "database\\/tables\\/.*" });
}

class HmsConstants
{
public:
    // errors
};
