#pragma once

#include "../../helpers/hmsuihelper.h"
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
    ~SignUpMainPage();
    
signals:
    void goTo(const QString& className);
    
private slots:
    void goToSignInPage();
    void watchPassword();
    void signUp();

private:
    Ui::SignUpMainPage* m_ui;
};
