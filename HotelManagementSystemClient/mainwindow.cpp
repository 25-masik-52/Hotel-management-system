#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow{ parent }
    , m_ui{ new Ui::MainWindow }
    , m_client{ new HmsClient{} }
    , m_popup{ new HmsPopupWidget{ this } }
    , m_signInPage{ new SignInMainPage }
    , m_signUpPage{ new SignUpMainPage }
{
    m_ui->setupUi(this);
    
    if (!m_client->connect("https://localhost"))
    {
        auto* portLineEdit = new QLineEdit{};
        portLineEdit->setObjectName("portLineEdit");
        portLineEdit->setPlaceholderText("Try another port");
        portLineEdit->setFont(HmsUiHelper::Regular_Font);
        portLineEdit->setStyleSheet("color: #003049; background: transparent; font-family: 'TT Wellingtons';");
        
        m_popup->setParent(m_signInPage);
        
        m_popup->setTitle("No connection!")
            ->addInfoRows({ { "Your application is trying to\nconnect to the server via port\n2643. Check the port with the\nadministrator and try again." } }, true)
            ->addLineEdit(portLineEdit)
            ->setButtons(HmsPopupButtons::Refresh);
        m_popup->getButton(HmsPopupButtons::Refresh)->setText("Try again");
        
        connect(m_popup->getButton(HmsPopupButtons::Refresh), &QPushButton::clicked,
                this, &MainWindow::connectToServer);
        
        m_popup->exec();
    }
    
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

void MainWindow::connectToServer()
{
    if (m_client->connect("https://localhost", m_popup->getLineEdit("portLineEdit")->displayText().trimmed().toUInt()))
        m_popup->close();
}

void MainWindow::goToAnotherWidget(const QString& className)
{    
    if (className == QString{ SignUpMainPage::staticMetaObject.className() })
        m_ui->stackedWidget->setCurrentWidget(m_signUpPage);
    else if (className == QString{ SignInMainPage::staticMetaObject.className() })
        m_ui->stackedWidget->setCurrentWidget(m_signInPage);
}
