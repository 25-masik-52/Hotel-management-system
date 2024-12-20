#include "hmspopupwidget.h"
#include "ui_hmspopupwidget.h"

HmsPopupWidget::HmsPopupWidget(QWidget *parent)
    : QWidget{ parent }
    , m_ui{ new Ui::HmsPopupWidget }
{
    m_ui->setupUi(this);
}

HmsPopupWidget::~HmsPopupWidget()
{
    delete m_ui;
}
