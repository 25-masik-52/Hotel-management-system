#pragma once

#include <QString>
#include <QDateTime>

struct User
{
    QString login;
    QString password;
    QString name;
    QDateTime createdAt;
};

struct Order
{
    QDateTime from;
    QDateTime to;
    QDateTime madeAt;
};

class HmsObjects
{
public:
    HmsObjects();
};

