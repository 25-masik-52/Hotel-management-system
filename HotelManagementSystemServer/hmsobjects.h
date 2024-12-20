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

struct Client
{
    uint socket;
    QString login;
    QDateTime connectedAt;
};

struct Order
{
    QDateTime from;
    QDateTime to;
    QDateTime madeAt;
};

struct UOR
{
    uint userId;
    uint orderId;
    uint roomId;
};

struct Rate
{
    UOR uor;
    uint8_t rate;
};

class HmsObjects
{
public:
    HmsObjects();
};


