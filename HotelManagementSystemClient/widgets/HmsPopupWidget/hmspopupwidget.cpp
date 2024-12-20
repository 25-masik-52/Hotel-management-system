#include "hmspopupwidget.h"
#include "ui_hmspopupwidget.h"

HmsPopupWidget::HmsPopupWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::HmsPopupWidget)
{
    ui->setupUi(this);
}

HmsPopupWidget::~HmsPopupWidget()
{
    delete ui;
}
