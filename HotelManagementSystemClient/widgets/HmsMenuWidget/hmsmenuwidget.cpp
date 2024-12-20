#include "hmsmenuwidget.h"
#include "ui_hmsmenuwidget.h"

HmsMenuWidget::HmsMenuWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::HmsMenuWidget)
{
    ui->setupUi(this);
}

HmsMenuWidget::~HmsMenuWidget()
{
    delete ui;
}
