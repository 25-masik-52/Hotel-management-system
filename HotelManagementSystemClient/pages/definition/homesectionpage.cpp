#include "homesectionpage.h"
#include "ui_homesectionpage.h"

HomeSectionPage::HomeSectionPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::HomeSectionPage)
{
    ui->setupUi(this);
}

HomeSectionPage::~HomeSectionPage()
{
    delete ui;
}
