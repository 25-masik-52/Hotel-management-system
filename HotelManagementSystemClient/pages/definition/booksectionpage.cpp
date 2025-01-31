#include "booksectionpage.h"
#include "../forms/ui_booksectionpage.h"

BookSectionPage::BookSectionPage(QWidget* parent)
    : QWidget{ parent }
    , m_ui{ new Ui::BookSectionPage }
{
    m_ui->setupUi(this);
}
