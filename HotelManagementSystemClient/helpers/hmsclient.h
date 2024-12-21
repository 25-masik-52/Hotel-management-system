#pragma once

#include "hmsobjects.h"
#include <QObject>
#include <QList>
#include <QTcpSocket>

class HmsClient : public QObject
{
    Q_OBJECT
    
public:
    HmsClient(QObject *parent = nullptr);
    
public:
    bool connect(const QString &host, quint16 port = 2643);
    bool addUser(const User &user);
    bool changeUserData(const User &user);
    bool deleteUser(const QString &login);
    User getUserByLogin(const QString &login);
    bool book(const Order &order);
    bool removeOrder(int orderId);
    QList<Order> getOrders();
    QStringList getOrderedRoomsByDate(const QDate &date);
    bool rateOrder(int orderId, int rating);
    
private:
    QTcpSocket* m_socket;
};
