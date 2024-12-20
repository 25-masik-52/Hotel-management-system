#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow{ parent }
    , m_ui{ new Ui::MainWindow }
    , m_signInPage{ new SignInMainPage }
    , m_signUpPage{ new SignUpMainPage }
{
    m_ui->setupUi(this);
    
    m_ui->stackedWidget->addWidget(m_signInPage);
    m_ui->stackedWidget->addWidget(m_signUpPage);
    
    connect(m_signInPage, &SignInMainPage::goTo,
            this, &MainWindow::goToAnotherWidget);
    
    connect(m_signUpPage, &SignUpMainPage::goTo,
            this, &MainWindow::goToAnotherWidget);
}

MainWindow::~MainWindow()
{
    delete m_ui;
}

void MainWindow::goToAnotherWidget(const QString& className)
{    
    if (className == QString{ SignUpMainPage::staticMetaObject.className() })
        m_ui->stackedWidget->setCurrentWidget(m_signUpPage);
    else if (className == QString{ SignInMainPage::staticMetaObject.className() })
        m_ui->stackedWidget->setCurrentWidget(m_signInPage);
}
