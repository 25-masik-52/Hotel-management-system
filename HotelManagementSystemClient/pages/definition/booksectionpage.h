#ifndef BOOKSECTIONPAGE_H
#define BOOKSECTIONPAGE_H

#include <QWidget>

namespace Ui {
class BookSectionPage;
}

class BookSectionPage : public QWidget
{
    Q_OBJECT

public:
    explicit BookSectionPage(QWidget *parent = nullptr);
    ~BookSectionPage();

private:
    Ui::BookSectionPage *ui;
};

#endif // BOOKSECTIONPAGE_H
