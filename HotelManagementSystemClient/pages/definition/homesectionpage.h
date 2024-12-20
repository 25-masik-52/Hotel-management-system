#pragma once

#include <QWidget>

namespace Ui {
class HomeSectionPage;
}

class HomeSectionPage : public QWidget
{
    Q_OBJECT

public:
    explicit HomeSectionPage(QWidget *parent = nullptr);
    ~HomeSectionPage();

private:
    Ui::HomeSectionPage* m_ui;
};
