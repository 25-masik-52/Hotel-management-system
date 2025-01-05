#include "signinmainpage.h"
#include "../forms/ui_signinmainpage.h"

SignInMainPage::SignInMainPage(QWidget* parent)
    : QWidget{ parent }
    , m_ui{ new Ui::SignInMainPage }
    , m_controlHelper{ new HmsControlHelper }
{
    m_ui->setupUi(this);
    
    m_ui->loginLineEdit->setTextMargins(10, 0, 0, 0);
    m_ui->passwordLineEdit->setTextMargins(10, 0, 0, 0);
    
    m_ui->errorLabel->setVisible(false);
    
    initActions();
    
    connect(m_ui->signInButton, &QPushButton::clicked,
            this, &SignInMainPage::signInClicked);
    
    connect(m_ui->signUpButton, &QPushButton::clicked,
            this, &SignInMainPage::goToClicked);
    
    for (auto* widget : this->findChildren<QWidget*>())
        m_ui->gridLayout->setAlignment(widget, Qt::AlignmentFlag::AlignHCenter);
}

void SignInMainPage::setClientError(const QString& error)
{
    m_ui->errorLabel->setText(error);
    m_ui->errorLabel->setVisible(true);
}

void SignInMainPage::signInClicked()
{
    if (!areFieldsValid())
        return;
    
    // sign in
    qDebug() << "sing in";
}

void SignInMainPage::goToClicked()
{
    // go to sign up
    qDebug() << "go to sign up";
}

void SignInMainPage::initActions()
{
    m_controlHelper->setWatchPasswordAction(m_ui->passwordLineEdit);
}

bool SignInMainPage::areFieldsValid()
{
    int isValid = 1;
    auto errorMessage = QString{ "%1 empty!" };
    
    if (m_controlHelper->isFieldEmpty(m_ui->loginLineEdit))
        isValid <<= 1;
    if (m_controlHelper->isFieldEmpty(m_ui->passwordLineEdit))
        isValid <<= 2;
    
    if (isValid == 2)
        m_ui->errorLabel->setText(errorMessage.arg("Login is"));
    else if (isValid == 4)
        m_ui->errorLabel->setText(errorMessage.arg("Password is"));
    else if (isValid == 8)
        m_ui->errorLabel->setText(errorMessage.arg("Login and password are"));
    
    m_ui->errorLabel->setVisible(isValid % 2 == 0);
        
    return isValid == 1;
}
