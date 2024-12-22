#pragma once

#include <QString>
#include <QRegularExpression>

class HmsConstants
{
public:
    static const quint16 Client_Default_Port;
    
    static const QByteArrayView Encrypt_Sha256_Key;
    
    static const QRegularExpression Medium_Passwords_Rx;
    static const QRegularExpression Hard_Passwords_Rx;
    
    static const QString Empty_LoginField_Error;
    static const QString Empty_PasswordField_Error;
    static const QString Empty_RepeatField_Error;
    
    static const QString Incorrect_Login_Error;
    static const QString Incorrect_Password_Error;
    
    static const QString NotMatch_PasswordFields_Error;
    static const QString Easy_Password_Error;
    static const QString Medium_Password_Error;
    static const QString Hard_Password_Info;
};
