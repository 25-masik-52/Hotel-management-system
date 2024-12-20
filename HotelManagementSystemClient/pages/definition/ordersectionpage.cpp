#include "ordersectionpage.h"
#include "ui_ordersectionpage.h"

OrderSectionPage::OrderSectionPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::OrderSectionPage)
{
    ui->setupUi(this);
}

OrderSectionPage::~OrderSectionPage()
{
    delete ui;
}
