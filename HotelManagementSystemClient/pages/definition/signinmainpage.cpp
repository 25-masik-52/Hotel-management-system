#include "signinmainpage.h"
#include "ui_signinmainpage.h"

SignInMainPage::SignInMainPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SignInMainPage)
{
    ui->setupUi(this);
}

SignInMainPage::~SignInMainPage()
{
    delete ui;
}
