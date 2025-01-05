#pragma once

#include "pages/definition/signinmainpage.h"

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

private:
    Ui::MainWindow* m_ui;
    SignInMainPage* m_signInPage;
    
private:
    void initStyleSheets();
};
