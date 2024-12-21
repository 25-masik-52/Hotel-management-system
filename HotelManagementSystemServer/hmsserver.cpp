#include "hmsserver.h"

HmsServer::HmsServer(uint port, const HmsDatabase& database, QObject *parent)
    : QObject{ parent }
    , m_port{ port }
    , m_server{ new QTcpServer(this) }
    , m_database{ database }
{
    connect(m_server, &QTcpServer::newConnection, this, &HmsServer::onNewConnection);
    
    if (!m_server->listen(QHostAddress::Any, m_port)) {
        qDebug() << "Не удалось запустить сервер:" << m_server->errorString();
    }
}

void HmsServer::onNewConnection()
{
    QTcpSocket* clientSocket = m_server->nextPendingConnection();
    if (clientSocket) {
        m_clients.append(clientSocket);
        
        qDebug() << "Новое подключение по адресу:" << clientSocket->peerAddress().toString();
        
        connect(clientSocket, &QTcpSocket::readyRead,
                this, &HmsServer::clientSentRequest);
    }
}

void HmsServer::clientSentRequest()
{
    
}
