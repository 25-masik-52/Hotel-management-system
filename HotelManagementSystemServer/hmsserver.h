#pragma once

#include "hmsdatabase.h"
#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>

class HmsServer : public QObject
{
    Q_OBJECT
public:
    explicit HmsServer(uint port, const HmsDatabase& database, QObject *parent = nullptr);
    
private slots:
    void onNewConnection();
    void clientSentRequest();
    
private:
    uint m_port;
    QTcpServer* m_server;
    QList<QTcpSocket*> m_clients;
    HmsDatabase m_database;
};
