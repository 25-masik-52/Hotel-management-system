#ifndef HMSCONFIGURATOR_H
#define HMSCONFIGURATOR_H

#include <QObject>

class HmsConfigurator : public QObject
{
    Q_OBJECT
public:
    explicit HmsConfigurator(QObject *parent = nullptr);

signals:
};

#endif // HMSCONFIGURATOR_H
