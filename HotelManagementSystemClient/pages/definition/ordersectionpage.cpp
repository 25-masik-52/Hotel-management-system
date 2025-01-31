#include "ordersectionpage.h"
#include "../forms/ui_ordersectionpage.h"

OrderSectionPage::OrderSectionPage(QWidget* parent)
    : QWidget{ parent }
    , m_ui{ new Ui::OrderSectionPage }
{
    m_ui->setupUi(this);
}
