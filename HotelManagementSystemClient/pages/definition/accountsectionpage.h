#pragma once

#include <QWidget>

namespace Ui {
class AccountSectionPage;
}

class AccountSectionPage : public QWidget
{
    Q_OBJECT

public:
    explicit AccountSectionPage(QWidget* parent = nullptr);
    ~AccountSectionPage() = default;

private:
    Ui::AccountSectionPage* m_ui;
};
