#ifndef SIGNINMAINPAGE_H
#define SIGNINMAINPAGE_H

#include <QWidget>

namespace Ui {
class SignInMainPage;
}

class SignInMainPage : public QWidget
{
    Q_OBJECT

public:
    explicit SignInMainPage(QWidget *parent = nullptr);
    ~SignInMainPage();

private:
    Ui::SignInMainPage *ui;
};

#endif // SIGNINMAINPAGE_H
