#pragma once

#include "helpers/hmsclient.h"
#include "widgets/HmsPopupWidget/hmspopupwidget.h"
#include "pages/definition/signinmainpage.h"
#include "pages/definition/signupmainpage.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    
private slots:
    void connectToServer();
    void goToAnotherWidget(const QString& className);

private:
    Ui::MainWindow* m_ui;
    
    HmsClient* m_client;
    
    HmsPopupWidget* m_popup;
    
    SignInMainPage* m_signInPage;
    SignUpMainPage* m_signUpPage;
};
