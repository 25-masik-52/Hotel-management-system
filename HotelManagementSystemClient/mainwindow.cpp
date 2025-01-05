#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "helpers/hmsuihelper.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow{ parent }
    , m_ui{ new Ui::MainWindow }
    , m_signInPage{ new SignInMainPage }
{
    m_ui->setupUi(this);
    
    initStyleSheets();
    
    m_ui->stackedWidget->addWidget(m_signInPage);
}

void MainWindow::initStyleSheets()
{
    HmsUiHelper::setStyleSheet(this);
    HmsUiHelper::setStyleSheet(m_signInPage);
}
