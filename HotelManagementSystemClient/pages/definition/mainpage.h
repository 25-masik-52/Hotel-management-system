#pragma once

#include "hmsmenuwidget.h"
#include <QWidget>

namespace Ui {
class MainPage;
}

class MainPage : public QWidget
{
    Q_OBJECT

public:
    explicit MainPage(QWidget* parent = nullptr);
    ~MainPage() = default;

private:
    Ui::MainPage* m_ui;
    HmsMenuWidget* m_menuWidget;
};
