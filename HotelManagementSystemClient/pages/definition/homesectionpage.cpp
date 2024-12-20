#include "homesectionpage.h"
#include "../forms/ui_homesectionpage.h"

HomeSectionPage::HomeSectionPage(QWidget *parent)
    : QWidget{ parent }
    , m_ui{ new Ui::HomeSectionPage }
{
    m_ui->setupUi(this);
}

HomeSectionPage::~HomeSectionPage()
{
    delete m_ui;
}
