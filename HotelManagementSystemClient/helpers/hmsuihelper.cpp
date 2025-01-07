#include "hmsuihelper.h"
#include "../mainwindow.h"

const QColor HmsUiHelper::HMS_COLOR_RED{ 193, 18, 31 };
const QColor HmsUiHelper::HMS_COLOR_DARK_BLUE{ 0, 48, 73 };

const int HmsUiHelper::HMS_ACTION_ICON_DEFAULT_SIZE = 24;

const QString HmsUiHelper::HMS_ICON_CLOSED_EYE{ ":/icons/assets/icons/closed_eye_icon.svg" };
const QString HmsUiHelper::HMS_ICON_OPENED_EYE{ ":/icons/assets/icons/opened_eye_icon.svg" };

void HmsUiHelper::setStyleSheet(QWidget* widget)
{
    QFile qssFile{ m_qssFiles.value(widget->metaObject()->className(), {}) };
    if (qssFile.open(QFile::ReadOnly))
        widget->setStyleSheet(QLatin1String{ qssFile.readAll() });
    else
        qCritical() << QString{ "[MainWindow::MainWindow] Couldn`t open %1!" }.arg(qssFile.fileName());
}

QString HmsUiHelper::changeStyleSheetProperty(const QString& styleSheet, const QString& property, const QString& value)
{
    QString res{ styleSheet };
    static QRegularExpression rx{ QString{ "^%1:.*;$" }.arg(property) };
    
    if (rx.match(res).hasMatch())
        res.replace(rx, QString{ "%1: %2;" }.arg(property, value));
    else
        res.append(QString{ (res.endsWith(";") ? "" : ";") }.append("\n%1: %2;").arg(property, value));
    
    return res;
}

QIcon HmsUiHelper::createIconFromSvg(const QString& svgFilePath, const QColor& color, int width, int height)
{
    QSvgRenderer svgRenderer{ svgFilePath };
    
    QPixmap pixmap{ width, height };
    pixmap.fill(Qt::transparent);
    
    QPainter painter{ &pixmap };
    painter.setRenderHint(QPainter::Antialiasing);
    
    svgRenderer.render(&painter);
    
    QGraphicsScene scene;
    QGraphicsPixmapItem item{ pixmap };
    
    auto* colorizeEffect = new QGraphicsColorizeEffect{};
    colorizeEffect->setColor(color);
    item.setGraphicsEffect(colorizeEffect);
    scene.addItem(&item);
    scene.render(&painter);
    
    return QIcon{ pixmap };
}

const QMap<QString, QString> HmsUiHelper::m_qssFiles
{
    { MainWindow::staticMetaObject.className(), ":/qss/assets/qss/main.qss" },
    { SignInMainPage::staticMetaObject.className(), ":/qss/assets/qss/signIn.qss" },
    { SignUpMainPage::staticMetaObject.className(), ":/qss/assets/qss/signUp.qss" },
    { MainPage::staticMetaObject.className(), ":/qss/assets/qss/mainPage.qss" }
};

