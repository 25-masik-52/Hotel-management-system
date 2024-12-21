#include "hmsclient.h"

HmsClient::HmsClient(QObject *parent)
    : QObject{ parent },
    m_socket{ new QTcpSocket{ this } }
{}

bool HmsClient::connect(const QString &host, quint16 port)
{
    m_socket->connectToHost(host, port);
    return m_socket->waitForConnected(3000);
}

bool HmsClient::addUser(const User &user)
{
    
}

bool HmsClient::changeUserData(const User &user)
{
    
}

bool HmsClient::deleteUser(const QString &login)
{
    
}

User HmsClient::getUserByLogin(const QString &login)
{
    
}

bool HmsClient::book(const Order &order)
{
    
}

bool HmsClient::removeOrder(int orderId)
{
    
}

QList<Order> HmsClient::getOrders()
{
    
}

QStringList HmsClient::getOrderedRoomsByDate(const QDate &date)
{
    
}

bool HmsClient::rateOrder(int orderId, int rating)
{
    
}
