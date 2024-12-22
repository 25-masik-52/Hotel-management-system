#include "signupmainpage.h"
#include "../forms/ui_signupmainpage.h"

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
    
    initEffects();
    initActions();
    
    connect(m_ui->signUpButton, &QPushButton::clicked,
            this, &SignUpMainPage::signUpClicked);
    
    connect(m_ui->goBackButton, &QPushButton::clicked,
            this, &SignUpMainPage::goToSignInPage);
    
    for (auto* widget : this->findChildren<QWidget*>())
        m_ui->verticalLayout->setAlignment(widget, Qt::AlignmentFlag::AlignHCenter);
}

void SignUpMainPage::signUpClicked()
{
    if (!areFieldsValid())
        return;
    
    emit signUp(m_ui->loginLineEdit->text(), m_controlHelper->encryptSha256(m_ui->passwordLineEdit->text()));
}

void SignUpMainPage::goToSignInPage()
{
    emit goTo(QString{ SignInMainPage::staticMetaObject.className() });
}

void SignUpMainPage::initEffects()
{
    HmsUiHelper::setButtonDropShadow(m_ui->signUpButton);
}

void SignUpMainPage::initActions()
{
    m_controlHelper->setWatchPasswordAction(m_ui->passwordLineEdit);
    m_controlHelper->setWatchPasswordAction(m_ui->repeatLineEdit);
}

bool SignUpMainPage::areFieldsValid()
{
    bool validLogin = m_controlHelper->isFieldValid(m_ui->loginLineEdit,
                                                    HmsConstants::Empty_LoginField_Error,
                                                    m_ui->errorLabel);
    
    bool validPassword = m_controlHelper->isFieldValid(m_ui->passwordLineEdit,
                                                       HmsConstants::Empty_PasswordField_Error,
                                                       m_ui->errorLabel);
    
    bool validRepeat = m_controlHelper->isFieldValid(m_ui->repeatLineEdit,
                                                     HmsConstants::Empty_RepeatField_Error,
                                                     m_ui->errorLabel);
    
    bool validPasswordHardness = m_controlHelper->checkPasswordHardness(m_ui->passwordLineEdit, m_ui->errorLabel);
    
    bool validPasswords = m_controlHelper->checkPasswordsEquaity(m_ui->passwordLineEdit,
                                                                 m_ui->repeatLineEdit,
                                                                 m_ui->errorLabel);
        
    return validLogin && validPassword && validRepeat && validPasswordHardness && validPasswords;
}
