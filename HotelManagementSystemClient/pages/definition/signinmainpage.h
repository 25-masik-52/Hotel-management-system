#pragma once

#include <QWidget>

namespace Ui {
class SignInMainPage;
}

class SignInMainPage : public QWidget
{
    Q_OBJECT

public:
    explicit SignInMainPage(QWidget *parent = nullptr);
    ~SignInMainPage();
    
signals:
    void goTo(const QString& className);
    
//private slots:
    //void goToSignUpPage();
    //void watchPassword();

private:
    Ui::SignInMainPage* m_ui;
};

