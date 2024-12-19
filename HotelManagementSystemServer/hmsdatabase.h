#ifndef HMSDATABASE_H
#define HMSDATABASE_H

#include <QObject>

class HmsDatabase : public QObject
{
    Q_OBJECT
public:
    explicit HmsDatabase(QObject *parent = nullptr);

signals:
};

#endif // HMSDATABASE_H
