#include "hmscontrolhelper.h"
#include "hmsuihelper.h"

HmsWatchPasswordAction::HmsWatchPasswordAction()
    : m_watchPasswordActionIconPath{ HmsUiHelper::HMS_ICON_CLOSED_EYE }
    , m_watchPasswordActionIconColor{ HmsUiHelper::HMS_COLOR_DARK_BLUE }
{
    changeIcon();
}

void HmsWatchPasswordAction::setIconPath(const QString& path)
{
    m_watchPasswordActionIconPath = path;
    changeIcon();
}

void HmsWatchPasswordAction::setIconColor(const QColor& color)
{
    m_watchPasswordActionIconColor = color;
    changeIcon();
}

void HmsWatchPasswordAction::changeIcon()
{
    setIcon(HmsUiHelper::createIconFromSvg(m_watchPasswordActionIconPath, m_watchPasswordActionIconColor));
}

void HmsControlHelper::setWatchPasswordAction(QLineEdit* lineEdit)
{
    auto* watchPasswordAction = new HmsWatchPasswordAction{};
    watchPasswordAction->setParent(lineEdit);
    lineEdit->addAction(watchPasswordAction, QLineEdit::TrailingPosition);
    
    connect(watchPasswordAction, &QAction::triggered,
            this, &HmsControlHelper::watchPassword);
}

bool HmsControlHelper::isFieldEmpty(QLineEdit* field)
{
    auto isEmpty = field->text().isEmpty();
    colorizeField(field, isEmpty ? HmsUiHelper::HMS_COLOR_RED : HmsUiHelper::HMS_COLOR_DARK_BLUE);
    
    return isEmpty;
}

bool HmsControlHelper::isFieldsEqual(QLineEdit* firstField, QLineEdit* secondField)
{
    auto isEqual = firstField->text() == secondField->text();
    colorizeField(firstField, isEqual ? HmsUiHelper::HMS_COLOR_DARK_BLUE : HmsUiHelper::HMS_COLOR_RED);
    colorizeField(secondField, isEqual ? HmsUiHelper::HMS_COLOR_DARK_BLUE : HmsUiHelper::HMS_COLOR_RED);
    
    return isEqual;
}

void HmsControlHelper::watchPassword()
{
    auto* senderAction = static_cast<HmsWatchPasswordAction*>(sender());
    auto* senderLineEdit = static_cast<QLineEdit*>(senderAction->parent());
    
    if (!senderAction)
    {
        qWarning() << "[HmsControlHelper::watchPassword] No action!";
        return;
    }
    if (!senderLineEdit)
    {
        qWarning() << "[HmsControlHelper::watchPassword] No lineEdit!";
        return;
    }
    
    const auto echoMode = senderLineEdit->echoMode() == QLineEdit::Normal ? QLineEdit::Password : QLineEdit::Normal;
    senderLineEdit->setEchoMode(echoMode);
    
    senderAction->setIconPath(echoMode == QLineEdit::Normal
                                  ? HmsUiHelper::HMS_ICON_OPENED_EYE
                                  : HmsUiHelper::HMS_ICON_CLOSED_EYE);
}

void HmsControlHelper::colorizeField(QLineEdit* field, const QColor& color)
{
    field->setStyleSheet(HmsUiHelper::changeStyleSheetProperty(field->styleSheet(), "color", color.name()));
    
    const auto actions = field->actions();
    const auto watchPasswordActionIter = std::find_if(actions.begin(), actions.end(),
                                                      [] (QAction* action)
                                                      {
                                                          return dynamic_cast<HmsWatchPasswordAction*>(action) != nullptr;
                                                      });
    
    if (watchPasswordActionIter != actions.end())
        dynamic_cast<HmsWatchPasswordAction*>(*watchPasswordActionIter)->setIconColor(color);
}
