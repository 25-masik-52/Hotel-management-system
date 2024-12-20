#include "hmsmenuwidget.h"
#include "ui_hmsmenuwidget.h"

HmsMenuWidget::HmsMenuWidget(QWidget *parent)
    : QWidget{ parent }
    , m_ui{ new Ui::HmsMenuWidget }
{
    m_ui->setupUi(this);
}

HmsMenuWidget::~HmsMenuWidget()
{
    delete m_ui;
}
