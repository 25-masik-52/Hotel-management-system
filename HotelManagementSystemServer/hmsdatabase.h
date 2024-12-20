#pragma once

#include "hmsobjects.h"
#include <QObject>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

class HmsDatabase
{
    Q_OBJECT
public:
    HmsDatabase() = default;
    explicit HmsDatabase(const QString& databaseName,
                         const QStringList& initConfigurations = {});
    
    ~HmsDatabase();
    
public:
    void insertUser(const User& user);
    void deleteUser(const QString& userLogin);
    User getUserByLogin(const QString& userLogin);
    void addClient(const Client& client);
    QList<Client> getClientsByLogin(const QString& userLogin);
    void addOrder(const Order& order);
    void deleteOrder(const Order& order);
    QList<Order> getOrdersByLogin(const QString& userLogin);
    QStringList getOrderedRoomsByDate(const QDateTime& from, const QDateTime& to);
    void addRate(const Rate& rate);
    
private:
    QSqlDatabase m_database;
};
