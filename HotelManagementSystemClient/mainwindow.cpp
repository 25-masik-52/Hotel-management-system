#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "helpers/hmsuihelper.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow{ parent }
    , m_ui{ new Ui::MainWindow }
    , m_signInPage{ new SignInMainPage }
    , m_signUpPage{ new SignUpMainPage }
{
    m_ui->setupUi(this);
    
    initStyleSheets();
    
    m_ui->stackedWidget->addWidget(m_signInPage);
    m_ui->stackedWidget->addWidget(m_signUpPage);
    
    connect(m_signInPage, &SignInMainPage::goTo,
            this, &MainWindow::goToEmitted);
    connect(m_signUpPage, &SignUpMainPage::goTo,
            this, &MainWindow::goToEmitted);
}

void MainWindow::goToEmitted(const QString& className)
{
    if (className == SignInMainPage::staticMetaObject.className())
        m_ui->stackedWidget->setCurrentWidget(m_signInPage);
    else if (className == SignUpMainPage::staticMetaObject.className())
        m_ui->stackedWidget->setCurrentWidget(m_signUpPage);
}

void MainWindow::initStyleSheets()
{
    HmsUiHelper::setStyleSheet(this);
    HmsUiHelper::setStyleSheet(m_signInPage);
    HmsUiHelper::setStyleSheet(m_signUpPage);
}
