#include "signinmainpage.h"
#include "../forms/ui_signinmainpage.h"

SignInMainPage::SignInMainPage(QWidget *parent)
    : QWidget{ parent }
    , m_ui{ new Ui::SignInMainPage }
{
    m_ui->setupUi(this);
    
    m_ui->loginLineEdit->setTextMargins(10, 0, 0, 0);
    m_ui->passwordLineEdit->setTextMargins(10, 0, 0, 0);
    
    m_ui->errorLabel->setVisible(false);
    
    auto* watchPasswordAction = new QAction{
        HmsUiHelper::createIconFromSvg(":/icons/assets/icons/closed_eye_icon.svg", QColor{ 0, 48, 73 }, 24, 24),
        {}
    };
    m_ui->passwordLineEdit->addAction(watchPasswordAction, QLineEdit::TrailingPosition);
    
    connect(watchPasswordAction, &QAction::triggered,
            this, &SignInMainPage::watchPassword);
    
    connect(m_ui->signUpButton, &QPushButton::clicked,
            this, &SignInMainPage::goToSignUpPage);
    
    for (auto* widget : this->findChildren<QWidget*>())
        m_ui->gridLayout->setAlignment(widget, Qt::AlignmentFlag::AlignHCenter);
}

SignInMainPage::~SignInMainPage()
{
    delete m_ui;
}

void SignInMainPage::goToSignUpPage()
{
    emit goTo(QString{ SignUpMainPage::staticMetaObject.className() });
}

void SignInMainPage::watchPassword()
{
    auto senderAction = static_cast<QAction*>(sender());
    
    if (!senderAction)
    {
        qWarning() << "[SignInPage::watchPassword] No action";
        return;
    }
    
    const auto echoMode = m_ui->passwordLineEdit->echoMode() == QLineEdit::Normal ? QLineEdit::Password : QLineEdit::Normal;
    m_ui->passwordLineEdit->setEchoMode(echoMode);
    
    QString pathToIcon = ":/icons/assets/icons/closed_eye_icon.svg";
    if (echoMode == QLineEdit::Normal)
        pathToIcon = ":/icons/assets/icons/opened_eye_icon.svg";
    
    senderAction->setIcon(HmsUiHelper::createIconFromSvg(pathToIcon, QColor{ 0, 48, 73 }, 24, 24));
}
