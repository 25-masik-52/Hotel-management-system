#ifndef HMSSERVER_H
#define HMSSERVER_H

#include <QObject>

class HmsServer : public QObject
{
    Q_OBJECT
public:
    explicit HmsServer(QObject *parent = nullptr);

signals:
};

#endif // HMSSERVER_H
