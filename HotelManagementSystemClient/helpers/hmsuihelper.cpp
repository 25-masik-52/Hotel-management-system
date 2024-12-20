#include "hmsuihelper.h"

const QFont HmsUiHelper::Regular_Font{ "TT Wellingtons", 14, QFont::Medium };
const QFont HmsUiHelper::Regular_Bold_Font{ "TT Wellingtons", 14, QFont::Bold };
const QFont HmsUiHelper::Small_Title_Font{ "Cinzel Decorative", 14, QFont::Bold };

const QColor HmsUiHelper::Error_Color{ 193, 18, 31 };
const QColor HmsUiHelper::MediumPassword_Color{ 221, 161, 94 };
const QColor HmsUiHelper::HardPassword_Color{ 106, 153, 78 };

QIcon HmsUiHelper::createIconFromSvg(const QString &svgFilePath, const QColor &color, int width, int height)
{
    QFile file{ svgFilePath };
    file.open(QIODevice::ReadOnly);
    QByteArray data = file.readAll();
    
    QDomDocument doc;
    doc.setContent(data);
    
    auto domElement = doc.documentElement();
    setAttributeRecursive(domElement, "path", "fill", color.name());
    
    
    QSvgRenderer svgRenderer{ doc.toByteArray() };
    QPixmap pix{ width, height };
    pix.fill(Qt::transparent);
    QPainter pixPainter{ &pix };
    svgRenderer.render(&pixPainter);
    
    return QIcon{ pix };
}

QString HmsUiHelper::changeStyleSheetProperty(const QString& styleSheet, const QString& property, const QString& value)
{
    QString res{ styleSheet };
    static QRegularExpression rx{ QString{ "%1:.*;" }.arg(property) };
    
    if (rx.match(res).hasMatch())
        res.replace(rx, QString{ "%1: %2;" }.arg(property, value));
    else
        res.append(QString{ (res.endsWith(";") ? "" : ";") }.append("\n%1: %2;").arg(property, value));
    
    return res;
}

void HmsUiHelper::setAttributeRecursive(QDomElement& elem, const QString& tagName, const QString& attribute,
                                     const QString& attributeValue)
{
    if (elem.tagName().compare(tagName) == 0)
        elem.setAttribute(attribute, attributeValue);
    
    for (int i = 0; i < elem.childNodes().count(); i++)
    {
        if (!elem.childNodes().at(i).isElement())
            continue;
        auto domElement = elem.childNodes().at(i).toElement();
        setAttributeRecursive(domElement, tagName, attribute, attributeValue);
    }
}
