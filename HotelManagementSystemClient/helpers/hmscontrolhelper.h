#pragma once

#include "hmsuihelper.h"
#include "hmsconstants.h"

#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QAction>
#include <QMessageAuthenticationCode>

class HmsControlHelper : public QWidget
{
    Q_OBJECT
    
public:
    void setWatchPasswordAction(QLineEdit* lineEdit);
    QString encryptSha256(const QString& text) const;
    bool isFieldValid(QLineEdit* sourceLineEdit, const QString& errorText = {}, QLabel* errorLineEdit = nullptr);
    bool checkPasswordHardness(QLineEdit* sourceLineEdit, QLabel* errorLineEdit);
    bool checkPasswordsEquaity(QLineEdit* firstLineEdit, QLineEdit* secondLineEdit, QLabel* errorLineEdit);
    
private slots:
    void watchPassword();
};
