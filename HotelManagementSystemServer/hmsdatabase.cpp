#include "hmsdatabase.h"

HmsDatabase::HmsDatabase(const QString& databaseName,
                         const QStringList& initConfigurations)
    : m_database{ QSqlDatabase::addDatabase("QSQLITE") }
{
    m_database.setDatabaseName(databaseName);
    
    if (!m_database.open()) {
        qDebug() << "Ошибка открытия базы данных:" << m_database.lastError().text();
        return;
    }
    
    for (const QString& queryStr : initConfigurations) {
        QSqlQuery query;
        if (!query.exec(queryStr)) {
            qDebug() << "Ошибка выполнения запроса:" << query.lastError().text();
        }
    }
}

HmsDatabase::~HmsDatabase()
{
    m_database.close();
}

void HmsDatabase::insertUser(const User& user)
{
    QSqlQuery query;
    query.prepare("INSERT INTO Users (Login, Password, Name, CreatedAt)"
                  "VALUES (:login, :password, :name, :date)");
    query.bindValue(":login", user.login);
    query.bindValue(":password", user.password);
    query.bindValue(":name", user.name);
    query.bindValue(":date", user.createdAt);
    
    if (!query.exec()) {
        qDebug() << "Error inserting user:" << query.lastError().text();
    }
}

void HmsDatabase::deleteUser(const QString& userLogin)
{
    QSqlQuery query;
    query.prepare("DELETE FROM Users WHERE login = :login");
    query.bindValue(":login", userLogin);
    
    if (!query.exec()) {
        qDebug() << "Error deleting user:" << query.lastError().text();
    }
}

User HmsDatabase::getUserByLogin(const QString& userLogin)
{
    User user;
    QSqlQuery query;
    query.prepare("SELECT * FROM Users WHERE login = :login");
    query.bindValue(":login", userLogin);
    
    if (query.exec() && query.next()) {
        user.login = query.value("Login").toString();
        user.password = query.value("Password").toString();
        user.name = query.value("Name").toString();
        user.createdAt = query.value("CreatedAt").toDateTime();
    } else {
        qDebug() << "Error getting user:" << query.lastError().text();
    }
    
    return user;
}

void HmsDatabase::addClient(const Client& client)
{
    QSqlQuery query;
    query.prepare("INSERT INTO Clients (Socket, Login, ConnectedAt) VALUES (:socket, :login, :date)");
    query.bindValue(":socket", client.socket);
    query.bindValue(":login", client.login);
    query.bindValue(":date", client.connectedAt);
    
    if (!query.exec()) {
        qDebug() << "Error adding client:" << query.lastError().text();
    }
}

QList<Client> HmsDatabase::getClientsByLogin(const QString& userLogin)
{
    QList<Client> clients;
    QSqlQuery query;
    query.prepare("SELECT * FROM Clients WHERE login = :login");
    query.bindValue(":login", userLogin);
    
    if (query.exec()) {
        while (query.next()) {
            Client client{};
            client.login = query.value("Login").toString();
            client.socket = query.value("Socket").toUInt();
            client.connectedAt = query.value("ConnectedAt").toDateTime();
            clients.append(client);
        }
    } else {
        qDebug() << "Error getting clients:" << query.lastError().text();
    }
    return clients;
}

void HmsDatabase::addOrder(const Order& order)
{
    QSqlQuery query;
    query.prepare("INSERT INTO Orders ([From], [To], MadeAt) VALUES (:from, :to, :date)");
    query.bindValue(":from", order.from);
    query.bindValue(":to", order.to);
    query.bindValue(":date", order.madeAt);
    
    if (!query.exec()) {
        qDebug() << "Error adding order:" << query.lastError().text();
    }
}

void HmsDatabase::deleteOrder(const Order& order)
{
    QSqlQuery query;
    query.prepare("DELETE FROM orders WHERE [From] = :from AND [To] = :to AND MadeAt = :date");
    query.bindValue(":from", order.from);
    query.bindValue(":to", order.to);
    query.bindValue(":date", order.madeAt);
    
    if (!query.exec()) {
        qDebug() << "Error deleting order:" << query.lastError().text();
    }
}

QList<Order> HmsDatabase::getOrdersByLogin(const QString& userLogin)
{
    
}

QStringList HmsDatabase::getOrderedRoomsByDate(const QDateTime& from, const QDateTime& to)
{
    
}

void HmsDatabase::addRate(const Rate& rate)
{
    
}
