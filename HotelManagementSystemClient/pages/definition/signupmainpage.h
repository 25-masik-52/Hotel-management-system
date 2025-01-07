#pragma once

#include "../../helpers/hmscontrolhelper.h"
#include <QWidget>

namespace Ui {
class SignUpMainPage;
}

class SignUpMainPage : public QWidget
{
    Q_OBJECT

public:
    explicit SignUpMainPage(QWidget* parent = nullptr);
    ~SignUpMainPage() = default;
    
public:
    void setClientError(const QString& error);
    
signals:
    void goTo(const QString& className);
    void signUp(const QString& login, const QString& password);
    
private slots:
    void signUpClicked();
    void goToClicked();

private:
    Ui::SignUpMainPage* m_ui;
    HmsControlHelper* m_controlHelper;
    
private:
    void initActions();
    bool areFieldsValid();
};
