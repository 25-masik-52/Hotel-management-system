#pragma once

#include <QWidget>
#include <QVideoWidget>

namespace Ui {
class HomeSectionPage;
}

class HomeSectionPage : public QWidget
{
    Q_OBJECT

public:
    explicit HomeSectionPage(QWidget* parent = nullptr);
    ~HomeSectionPage() = default;

private:
    Ui::HomeSectionPage* m_ui;
    QVideoWidget* m_videoWidget;
};
