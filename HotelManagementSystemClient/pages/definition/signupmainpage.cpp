#include "signupmainpage.h"
#include "../forms/ui_signupmainpage.h"

SignUpMainPage::SignUpMainPage(QWidget *parent)
    : QWidget{ parent }
    , m_ui{ new Ui::SignUpMainPage }
{
    m_ui->setupUi(this);
    
    m_ui->loginLineEdit->setTextMargins(10, 0, 0, 0);
    m_ui->passwordLineEdit->setTextMargins(10, 0, 0, 0);
    m_ui->repeatLineEdit->setTextMargins(10, 0, 0, 0);
    
    /*connect(m_ui->passwordLineEdit, &QLineEdit::textEdited,
            this, &SignUpMainPage::checkPasswords);
    connect(m_ui->repeatLineEdit, &QLineEdit::textEdited,
            this, &SignUpMainPage::checkPasswords);*/
    
    m_ui->errorLabel->setVisible(false);
    
    auto* watchPasswordAction = new QAction{
        HmsUiHelper::createIconFromSvg(":/icons/assets/icons/closed_eye_icon.svg", QColor{ 0, 48, 73 }, 24, 24),
        {}, m_ui->passwordLineEdit
    };
    m_ui->passwordLineEdit->addAction(watchPasswordAction, QLineEdit::TrailingPosition);
    connect(watchPasswordAction, &QAction::triggered,
            this, &SignUpMainPage::watchPassword);
    
    auto* watchRepeatAction = new QAction{
        HmsUiHelper::createIconFromSvg(":/icons/assets/icons/closed_eye_icon.svg", QColor{ 0, 48, 73 }, 24, 24),
        {}, m_ui->repeatLineEdit
    };
    m_ui->repeatLineEdit->addAction(watchRepeatAction, QLineEdit::TrailingPosition);
    connect(watchRepeatAction, &QAction::triggered,
            this, &SignUpMainPage::watchPassword);
    
    connect(m_ui->goBackButton, &QPushButton::clicked,
            this, &SignUpMainPage::goToSignInPage);
    
    connect(m_ui->signUpButton, &QPushButton::clicked,
            this, &SignUpMainPage::signUp);
    
    for (auto* widget : this->findChildren<QWidget*>())
        m_ui->gridLayout->setAlignment(widget, Qt::AlignmentFlag::AlignHCenter);
}

SignUpMainPage::~SignUpMainPage()
{
    delete m_ui;
}

void SignUpMainPage::goToSignInPage()
{
    emit goTo(QString{ SignInMainPage::staticMetaObject.className() });
}

void SignUpMainPage::watchPassword()
{
    auto senderAction = static_cast<QAction*>(sender());
    
    if (!senderAction)
    {
        qWarning() << "[SignUpPage::watchPassword] No action";
        return;
    }
    
    auto senderLineEdit = static_cast<QLineEdit*>(senderAction->parent());
    
    if (!senderLineEdit)
    {
        qWarning() << "[SignUpPage::watchPassword] No QLineEdit";
        return;
    }
    
    const auto echoMode = senderLineEdit->echoMode() == QLineEdit::Normal ? QLineEdit::Password : QLineEdit::Normal;
    senderLineEdit->setEchoMode(echoMode);
    
    QString pathToIcon = ":/icons/assets/icons/closed_eye_icon.svg";
    if (echoMode == QLineEdit::Normal)
        pathToIcon = ":/icons/assets/icons/opened_eye_icon.svg";
    
    senderAction->setIcon(HmsUiHelper::createIconFromSvg(pathToIcon, QColor{ 0, 48, 73 }, 24, 24));
}

void SignUpMainPage::signUp()
{
    
}

/*bool SignUpPage::checkErrors()
{
    if (m_ui->loginLineEdit->displayText().isEmpty())
    {
        // m_ui->errorLabel->setText(HmsConstants::EmptyLogin_Error);
        m_ui->errorLabel->setVisible(true);
        m_ui->errorLabel->setStyleSheet(UiHelper::changeStyleSheetProperty(m_ui->errorLabel->styleSheet(),
                                                                           "color",
                                                                           UiHelper::Error_Color.name()));
    }
    
    return m_ui->errorLabel->isVisible();
}*/
