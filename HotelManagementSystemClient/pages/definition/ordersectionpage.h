#ifndef ORDERSECTIONPAGE_H
#define ORDERSECTIONPAGE_H

#include <QWidget>

namespace Ui {
class OrderSectionPage;
}

class OrderSectionPage : public QWidget
{
    Q_OBJECT

public:
    explicit OrderSectionPage(QWidget *parent = nullptr);
    ~OrderSectionPage();

private:
    Ui::OrderSectionPage *ui;
};

#endif // ORDERSECTIONPAGE_H
