#pragma once

#include "../../helpers/hmscontrolhelper.h"
#include "signinmainpage.h"

#include <QWidget>

namespace Ui {
class SignUpMainPage;
}

class SignUpMainPage : public QWidget
{
    Q_OBJECT

public:
    explicit SignUpMainPage(QWidget *parent = nullptr);
    ~SignUpMainPage() = default;
    
signals:
    void signUp(const QString& login, const QString& password);
    void goTo(const QString& className);
    
private slots:
    void signUpClicked();
    void goToSignInPage();
    
private:
    Ui::SignUpMainPage* m_ui;
    HmsControlHelper* m_controlHelper;
    
private:
    void initEffects();
    void initActions();
    bool areFieldsValid();
};
