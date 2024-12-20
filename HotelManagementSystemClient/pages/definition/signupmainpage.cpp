#include "signupmainpage.h"
#include "../forms/ui_signupmainpage.h"

SignUpMainPage::SignUpMainPage(QWidget *parent)
    : QWidget{ parent }
    , m_ui{ new Ui::SignUpMainPage }
{
    m_ui->setupUi(this);
}

SignUpMainPage::~SignUpMainPage()
{
    delete m_ui;
}
