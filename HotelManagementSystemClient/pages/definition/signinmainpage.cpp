#include "signinmainpage.h"
#include "../forms/ui_signinmainpage.h"

SignInMainPage::SignInMainPage(QWidget *parent)
    : QWidget{ parent }
    , m_ui{ new Ui::SignInMainPage }
{
    m_ui->setupUi(this);
}

SignInMainPage::~SignInMainPage()
{
    delete m_ui;
}
