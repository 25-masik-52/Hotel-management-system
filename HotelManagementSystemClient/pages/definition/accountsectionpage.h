#ifndef ACCOUNTSECTIONPAGE_H
#define ACCOUNTSECTIONPAGE_H

#include <QWidget>

namespace Ui {
class AccountSectionPage;
}

class AccountSectionPage : public QWidget
{
    Q_OBJECT

public:
    explicit AccountSectionPage(QWidget *parent = nullptr);
    ~AccountSectionPage();

private:
    Ui::AccountSectionPage *ui;
};

#endif // ACCOUNTSECTIONPAGE_H
