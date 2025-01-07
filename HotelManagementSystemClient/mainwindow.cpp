#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "helpers/hmsuihelper.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow{ parent }
    , m_ui{ new Ui::MainWindow }
    , m_signInPage{ new SignInMainPage }
    , m_signUpPage{ new SignUpMainPage }
    , m_mainPage{ new MainPage }
{
    m_ui->setupUi(this);
    
    initStyleSheets();
    
    initStackedWidget();
    
    connectPages();
}

void MainWindow::goToEmitted(const QString& className)
{
    if (className == SignInMainPage::staticMetaObject.className())
        m_ui->stackedWidget->setCurrentWidget(m_signInPage);
    else if (className == SignUpMainPage::staticMetaObject.className())
        m_ui->stackedWidget->setCurrentWidget(m_signUpPage);
}

void MainWindow::signInEmitted(const QString& login, const QString& password)
{
    // work with server;
    
    // if true
    m_ui->stackedWidget->setCurrentWidget(m_mainPage);
    
    // if false
}

void MainWindow::initStyleSheets()
{
    HmsUiHelper::setStyleSheet(this);
    HmsUiHelper::setStyleSheet(m_signInPage);
    HmsUiHelper::setStyleSheet(m_signUpPage);
    HmsUiHelper::setStyleSheet(m_mainPage);
}

void MainWindow::initStackedWidget()
{
    m_ui->stackedWidget->addWidget(m_signInPage);
    m_ui->stackedWidget->addWidget(m_signUpPage);
    m_ui->stackedWidget->addWidget(m_mainPage);
}

void MainWindow::connectPages()
{
    connect(m_signInPage, &SignInMainPage::goTo,
            this, &MainWindow::goToEmitted);
    connect(m_signInPage, &SignInMainPage::signIn,
            this, &MainWindow::signInEmitted);
    connect(m_signUpPage, &SignUpMainPage::goTo,
            this, &MainWindow::goToEmitted);
}
