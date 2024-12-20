#include "hmsorderitemwidget.h"
#include "ui_hmsorderitemwidget.h"

HmsOrderItemWidget::HmsOrderItemWidget(QWidget *parent)
    : QWidget{ parent }
    , m_ui{ new Ui::HmsOrderItemWidget }
{
    m_ui->setupUi(this);
}

HmsOrderItemWidget::~HmsOrderItemWidget()
{
    delete m_ui;
}
