#include "mainpage.h"
#include "../forms/ui_mainpage.h"

MainPage::MainPage(QWidget* parent)
    : QWidget{ parent }
    , m_ui{ new Ui::MainPage }
    , m_menuWidget{ new HmsMenuWidget }
{
    m_ui->setupUi(this);
    m_ui->gridLayout->addWidget(m_menuWidget);
}
