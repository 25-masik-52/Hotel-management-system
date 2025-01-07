#include "signupmainpage.h"
#include "../forms/ui_signupmainpage.h"
#include "signinmainpage.h"

SignUpMainPage::SignUpMainPage(QWidget* parent)
    : QWidget{ parent }
    , m_ui{ new Ui::SignUpMainPage }
    , m_controlHelper{ new HmsControlHelper }
{
    m_ui->setupUi(this);
    
    m_ui->loginLineEdit->setTextMargins(10, 0, 0, 0);
    m_ui->passwordLineEdit->setTextMargins(10, 0, 0, 0);
    m_ui->repeatLineEdit->setTextMargins(10, 0, 0, 0);
    
    m_ui->errorLabel->setVisible(false);
    
    initActions();
    
    connect(m_ui->signUpButton, &QPushButton::clicked,
            this, &SignUpMainPage::signUpClicked);
    
    connect(m_ui->backButton, &QPushButton::clicked,
            this, &SignUpMainPage::goToClicked);
    
    for (auto* widget : this->findChildren<QWidget*>())
        m_ui->gridLayout->setAlignment(widget, Qt::AlignmentFlag::AlignHCenter);
}

void SignUpMainPage::setClientError(const QString& error)
{
    m_ui->errorLabel->setText(error);
    m_ui->errorLabel->setVisible(true);
}

void SignUpMainPage::signUpClicked()
{
    if (!areFieldsValid())
        return;
    
    // sign in
    qDebug() << "sing up";
}

void SignUpMainPage::goToClicked()
{
    emit goTo(SignInMainPage::staticMetaObject.className());
}

void SignUpMainPage::initActions()
{
    m_controlHelper->setWatchPasswordAction(m_ui->passwordLineEdit);
    m_controlHelper->setWatchPasswordAction(m_ui->repeatLineEdit);
}

bool SignUpMainPage::areFieldsValid()
{
    int isValid = 1;
    auto errorMessage = QString{ "%1 empty!" };
    
    if (m_controlHelper->isFieldEmpty(m_ui->loginLineEdit))
        isValid <<= 1;
    if (m_controlHelper->isFieldEmpty(m_ui->passwordLineEdit))
        isValid <<= 2;
    if (m_controlHelper->isFieldEmpty(m_ui->repeatLineEdit))
        isValid <<= 4;
    
    if (isValid == 2)
        m_ui->errorLabel->setText(errorMessage.arg("Login is"));
    else if (isValid == 4)
        m_ui->errorLabel->setText(errorMessage.arg("Password is"));
    else if (isValid == 8)
        m_ui->errorLabel->setText(errorMessage.arg("Login and password are"));
    else if (isValid == 16)
        m_ui->errorLabel->setText(errorMessage.arg("Repeat is"));
    else if (isValid == 32)
        m_ui->errorLabel->setText(errorMessage.arg("Login and repeat are"));
    else if (isValid == 64)
        m_ui->errorLabel->setText(errorMessage.arg("Password and repeat are"));
    else if (isValid == 128)
        m_ui->errorLabel->setText(errorMessage.arg("Login, password and repeat are"));
        
    if (!m_controlHelper->isFieldsEqual(m_ui->passwordLineEdit, m_ui->repeatLineEdit))
    {
        m_ui->errorLabel->setText("Password and repeat are different!");
        isValid = 0;
    }
        
    m_ui->errorLabel->setVisible(isValid % 2 == 0);
    
    return isValid == 1;
}
