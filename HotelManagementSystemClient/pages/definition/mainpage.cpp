#include "mainpage.h"
#include "../forms/ui_mainpage.h"

MainPage::MainPage(QWidget* parent)
    : QWidget{ parent }
    , m_ui{ new Ui::MainPage }
{
    m_ui->setupUi(this);
}
