#ifndef SIGNUPMAINPAGE_H
#define SIGNUPMAINPAGE_H

#include <QWidget>

namespace Ui {
class SignUpMainPage;
}

class SignUpMainPage : public QWidget
{
    Q_OBJECT

public:
    explicit SignUpMainPage(QWidget *parent = nullptr);
    ~SignUpMainPage();

private:
    Ui::SignUpMainPage *ui;
};

#endif // SIGNUPMAINPAGE_H
