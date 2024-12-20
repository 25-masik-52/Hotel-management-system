#include "accountsectionpage.h"
#include "ui_accountsectionpage.h"

AccountSectionPage::AccountSectionPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AccountSectionPage)
{
    ui->setupUi(this);
}

AccountSectionPage::~AccountSectionPage()
{
    delete ui;
}
