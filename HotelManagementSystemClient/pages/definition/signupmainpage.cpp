#include "signupmainpage.h"
#include "ui_signupmainpage.h"

SignUpMainPage::SignUpMainPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SignUpMainPage)
{
    ui->setupUi(this);
}

SignUpMainPage::~SignUpMainPage()
{
    delete ui;
}
