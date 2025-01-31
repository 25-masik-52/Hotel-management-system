#pragma once

#include <QWidget>

namespace Ui {
class OrderSectionPage;
}

class OrderSectionPage : public QWidget
{
    Q_OBJECT

public:
    explicit OrderSectionPage(QWidget* parent = nullptr);
    ~OrderSectionPage() = default;

private:
    Ui::OrderSectionPage* m_ui;
};
