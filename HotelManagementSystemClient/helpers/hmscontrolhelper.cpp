#include "hmscontrolhelper.h"

void HmsControlHelper::setWatchPasswordAction(QLineEdit* lineEdit)
{
    auto* watchPasswordAction = new QAction{
        HmsUiHelper::createIconFromSvg(":/icons/assets/icons/closed_eye_icon.svg", HmsUiHelper::Control_Color, 24, 24),
        {},
        lineEdit
    };
    lineEdit->addAction(watchPasswordAction, QLineEdit::TrailingPosition);
    
    connect(watchPasswordAction, &QAction::triggered,
            this, &HmsControlHelper::watchPassword);
}

QString HmsControlHelper::encryptSha256(const QString& text) const
{
    QMessageAuthenticationCode code(QCryptographicHash::Sha256);
    code.setKey(HmsConstants::Encrypt_Sha256_Key);
    code.addData(text.toUtf8());
    return QString::fromUtf8(code.result().toHex());
}

bool HmsControlHelper::isFieldValid(QLineEdit* sourceLineEdit, const QString& errorText, QLabel* errorLineEdit)
{
    bool valid = sourceLineEdit->text().isEmpty();
    sourceLineEdit->setStyleSheet(HmsUiHelper::changeStyleSheetProperty(sourceLineEdit->styleSheet(),
                                                                        "color",
                                                                        valid ? HmsUiHelper::Control_Color.name() : HmsUiHelper::Info_Color.name())
                                  );
    
    if (errorLineEdit)
    {
        errorLineEdit->setText(errorText);
        errorLineEdit->setVisible(!valid);
    }
    
    return valid;
}

bool HmsControlHelper::checkPasswordHardness(QLineEdit* sourceLineEdit, QLabel* errorLineEdit)
{
    bool isHard = false;
    QString color = HmsUiHelper::Info_Color.name();
    QString error = HmsConstants::Easy_Password_Error;
    
    const auto password = sourceLineEdit->text();
    errorLineEdit->setVisible(true);
    
    if (HmsConstants::Hard_Passwords_Rx.match(password).hasMatch())
    {
        isHard = true;
        color = HmsUiHelper::HardPassword_Color.name();
        error = HmsConstants::Hard_Password_Info;
    }
    else if (HmsConstants::Medium_Passwords_Rx.match(password).hasMatch())
    {
        color = HmsUiHelper::MediumPassword_Color.name();
        error = HmsConstants::Medium_Password_Error;
    }
    
    sourceLineEdit->setStyleSheet(HmsUiHelper::changeStyleSheetProperty(errorLineEdit->styleSheet(), "color", color));
    errorLineEdit->setText(error);
    
    return isHard;
}

bool HmsControlHelper::checkPasswordsEquaity(QLineEdit* firstLineEdit, QLineEdit* secondLineEdit, QLabel* errorLineEdit)
{   
    bool valid = firstLineEdit->text() == secondLineEdit->text();
    
    const auto firstStyle = HmsUiHelper::changeStyleSheetProperty(firstLineEdit->styleSheet(),
                                                                  "color",
                                                                  valid ? HmsUiHelper::Control_Color.name() : HmsUiHelper::Info_Color.name());
    
    const auto secondStyle = HmsUiHelper::changeStyleSheetProperty(secondLineEdit->styleSheet(),
                                                                   "color",
                                                                   valid ? HmsUiHelper::Control_Color.name() : HmsUiHelper::Info_Color.name());
    
    firstLineEdit->setStyleSheet(firstStyle);
    secondLineEdit->setStyleSheet(secondStyle);
    
    errorLineEdit->setText(HmsConstants::NotMatch_PasswordFields_Error);
    errorLineEdit->setVisible(!valid);
    
    return valid;
}

void HmsControlHelper::watchPassword()
{
    auto* senderAction = static_cast<QAction*>(sender());
    auto* senderLineEdit = static_cast<QLineEdit*>(senderAction->parent());
    
    if (!senderAction)
    {
        qWarning() << "[HmsControlHelper::watchPassword] No action";
        return;
    }
    if (!senderLineEdit)
    {
        qWarning() << "[HmsControlHelper::watchPassword] No lineEdit";
        return;
    }
    
    const auto echoMode = senderLineEdit->echoMode() == QLineEdit::Normal ? QLineEdit::Password : QLineEdit::Normal;
    senderLineEdit->setEchoMode(echoMode);
    
    QString pathToIcon = ":/icons/assets/icons/closed_eye_icon.svg";
    if (echoMode == QLineEdit::Normal)
        pathToIcon = ":/icons/assets/icons/opened_eye_icon.svg";
    
    senderAction->setIcon(HmsUiHelper::createIconFromSvg(pathToIcon, QColor{ 0, 48, 73 }, 24, 24));
}
