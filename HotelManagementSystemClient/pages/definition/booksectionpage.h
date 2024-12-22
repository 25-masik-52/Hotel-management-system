#pragma once

#include <QWidget>

namespace Ui {
class BookSectionPage;
}

class BookSectionPage : public QWidget
{
    Q_OBJECT

public:
    explicit BookSectionPage(QWidget* parent = nullptr);
    ~BookSectionPage() = default;

private:
    Ui::BookSectionPage* m_ui;
};
