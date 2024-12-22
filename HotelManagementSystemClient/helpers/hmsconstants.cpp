#include "hmsconstants.h"

const quint16 HmsConstants::Client_Default_Port{ 2643 };

const QByteArrayView HmsConstants::Encrypt_Sha256_Key{ "HmsClientEncriptKey" };

const QRegularExpression HmsConstants::Medium_Passwords_Rx{ "^(?=.*?[A-Z])(?=.*?[a-z])(?=.*?[0-9]).{5,}$" };
const QRegularExpression HmsConstants::Hard_Passwords_Rx{ "^(?=.*?[A-Z])(?=.*?[a-z])(?=.*?[0-9])(?=.*?[#?!@$%^&*-]).{8,}$" };

const QString HmsConstants::Empty_LoginField_Error{ "Login field is empty!" };
const QString HmsConstants::Empty_PasswordField_Error{ "Password field is empty!" };
const QString HmsConstants::Empty_RepeatField_Error{ "Repeat field is empty!" };

const QString HmsConstants::Incorrect_Login_Error{ "There is no user with this login!" };
const QString HmsConstants::Incorrect_Password_Error{ "Incorrect password!" };

const QString HmsConstants::NotMatch_PasswordFields_Error{ "Password do not match!" };
const QString HmsConstants::Easy_Password_Error{ "Password is too easy!" };
const QString HmsConstants::Medium_Password_Error{ "Medium password" };
const QString HmsConstants::Hard_Password_Info{ "Hard Password!" };
