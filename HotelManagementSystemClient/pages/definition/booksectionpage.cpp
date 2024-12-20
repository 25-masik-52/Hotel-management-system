#include "booksectionpage.h"
#include "ui_booksectionpage.h"

BookSectionPage::BookSectionPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::BookSectionPage)
{
    ui->setupUi(this);
}

BookSectionPage::~BookSectionPage()
{
    delete ui;
}
