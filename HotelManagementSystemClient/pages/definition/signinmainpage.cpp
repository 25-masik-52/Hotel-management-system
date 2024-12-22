#include "signinmainpage.h"
#include "../forms/ui_signinmainpage.h"

SignInMainPage::SignInMainPage(QWidget *parent)
    : QWidget{ parent }
    , m_ui{ new Ui::SignInMainPage }
    , m_controlHelper{ new HmsControlHelper }
{
    m_ui->setupUi(this);
    
    m_ui->loginLineEdit->setTextMargins(10, 0, 0, 0);
    m_ui->passwordLineEdit->setTextMargins(10, 0, 0, 0);
    
    m_ui->errorLabel->setVisible(false);
    
    initEffects();
    initActions();
    
    connect(m_ui->signInButton, &QPushButton::clicked,
            this, &SignInMainPage::signInClicked);
    
    connect(m_ui->signUpButton, &QPushButton::clicked,
            this, &SignInMainPage::goToSignUpPage);
    
    for (auto* widget : this->findChildren<QWidget*>())
        m_ui->verticalLayout->setAlignment(widget, Qt::AlignmentFlag::AlignHCenter);
}

void SignInMainPage::signInClicked()
{
    if (!areFieldsValid())
        return;
    
    emit signIn(m_ui->loginLineEdit->text(), m_controlHelper->encryptSha256(m_ui->passwordLineEdit->text()));
}

void SignInMainPage::goToSignUpPage()
{
    emit goTo(QString{ SignUpMainPage::staticMetaObject.className() });
}

void SignInMainPage::initEffects()
{
    HmsUiHelper::setButtonDropShadow(m_ui->signInButton);
}

void SignInMainPage::initActions()
{
    m_controlHelper->setWatchPasswordAction(m_ui->passwordLineEdit);
}

bool SignInMainPage::areFieldsValid()
{
    bool validLogin = m_controlHelper->isFieldValid(m_ui->loginLineEdit,
                                          HmsConstants::Empty_LoginField_Error,
                                          m_ui->errorLabel);
    
    bool validPassword = m_controlHelper->isFieldValid(m_ui->passwordLineEdit,
                                          HmsConstants::Empty_PasswordField_Error,
                                          m_ui->errorLabel);
    
    return validLogin && validPassword;
}
