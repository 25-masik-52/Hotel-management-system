#pragma once

#include <QWidget>

namespace Ui {
class HmsOrderItemWidget;
}

class HmsOrderItemWidget : public QWidget
{
    Q_OBJECT

public:
    explicit HmsOrderItemWidget(QWidget *parent = nullptr);
    ~HmsOrderItemWidget();

private:
    Ui::HmsOrderItemWidget* m_ui;
};
