#pragma once

#include "../../helpers/hmscontrolhelper.h"
#include "signupmainpage.h"

#include <QWidget>

namespace Ui {
class SignInMainPage;
}

class SignInMainPage : public QWidget
{
    Q_OBJECT

public:
    explicit SignInMainPage(QWidget *parent = nullptr);
    ~SignInMainPage() = default;
    
signals:
    void signIn(const QString& login, const QString& password);
    void goTo(const QString& className);
    
private slots:
    void signInClicked();
    void goToSignUpPage();
    
private:
    Ui::SignInMainPage* m_ui;
    HmsControlHelper* m_controlHelper;
    
private:
    void initEffects();
    void initActions();
    bool areFieldsValid();
};
