#pragma once

#include <QWidget>

namespace Ui {
class HmsMenuWidget;
}

class HmsMenuWidget : public QWidget
{
    Q_OBJECT

public:
    explicit HmsMenuWidget(QWidget *parent = nullptr);
    ~HmsMenuWidget();

private:
    Ui::HmsMenuWidget* m_ui;
};

