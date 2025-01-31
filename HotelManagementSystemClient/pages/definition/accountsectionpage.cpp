#include "accountsectionpage.h"
#include "../forms/ui_accountsectionpage.h"

AccountSectionPage::AccountSectionPage(QWidget* parent)
    : QWidget{ parent }
    , m_ui{ new Ui::AccountSectionPage }
{
    m_ui->setupUi(this);
}
