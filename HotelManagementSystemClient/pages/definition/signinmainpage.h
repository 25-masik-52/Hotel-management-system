#pragma once

#include "../../helpers/hmscontrolhelper.h"
#include <QWidget>

namespace Ui {
class SignInMainPage;
}

class SignInMainPage : public QWidget
{
    Q_OBJECT

public:
    explicit SignInMainPage(QWidget* parent = nullptr);
    ~SignInMainPage() = default;
    
public:
    void setClientError(const QString& error);
    
signals:
    void goTo(const QString& className);
    void signIn(const QString& login, const QString& password);
    
private slots:
    void signInClicked();
    void goToClicked();

private:
    Ui::SignInMainPage* m_ui;
    HmsControlHelper* m_controlHelper;
    
private:
    void initActions();
    bool areFieldsValid();
};
