#pragma once

#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QAction>
#include <QMessageAuthenticationCode>

class HmsWatchPasswordAction : public QAction
{
    
public:
    HmsWatchPasswordAction();
    ~HmsWatchPasswordAction() override = default;
    
public:
    void setIconPath(const QString& path);
    void setIconColor(const QColor& color);
    
private:
    QString m_watchPasswordActionIconPath;
    QColor m_watchPasswordActionIconColor;
    
private:
    void changeIcon();
};

class HmsControlHelper : public QWidget
{
    Q_OBJECT
    
public:
    HmsControlHelper() = default;
    
public:
    void setWatchPasswordAction(QLineEdit* lineEdit);
    bool isFieldEmpty(QLineEdit* field);
    
private slots:
    void watchPassword();
};
