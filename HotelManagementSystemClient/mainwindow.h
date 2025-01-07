#pragma once

#include "pages/definition/signinmainpage.h"
#include "pages/definition/signupmainpage.h"
#include "pages/definition/mainpage.h"

#include <QMainWindow>
#include <QFile>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow() = default;
    
private slots:
    void goToEmitted(const QString& className);
    void signInEmitted(const QString& login, const QString& password);

private:
    Ui::MainWindow* m_ui;
    SignInMainPage* m_signInPage;
    SignUpMainPage* m_signUpPage;
    MainPage* m_mainPage;
    
private:
    void initStyleSheets();
    void initStackedWidget();
    void connectPages();
};
