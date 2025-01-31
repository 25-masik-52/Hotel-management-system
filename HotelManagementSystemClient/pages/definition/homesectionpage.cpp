#include "homesectionpage.h"
#include "../forms/ui_homesectionpage.h"

HomeSectionPage::HomeSectionPage(QWidget* parent)
    : QWidget{ parent }
    , m_ui{ new Ui::HomeSectionPage }
    , m_videoWidget{ new QVideoWidget }
{
    m_ui->setupUi(this);
    
    m_ui->verticalLayout->addWidget(m_videoWidget);
}
