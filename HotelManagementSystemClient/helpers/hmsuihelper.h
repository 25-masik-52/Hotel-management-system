#pragma once

#include <QFont>
#include <QIcon>
#include <QDomElement>
#include <QSvgRenderer>
#include <QPainter>
#include <QRegularExpression>
#include <QFile>

class HmsUiHelper
{  
public:
    static const QFont Regular_Font;
    static const QFont Small_Title_Font;
    static const QFont Regular_Bold_Font;
    
    static const QColor Error_Color;
    static const QColor MediumPassword_Color;
    static const QColor HardPassword_Color;
    
public:
    static QIcon createIconFromSvg(const QString &svgFilePath, const QColor &color, int width, int height);
    static QString changeStyleSheetProperty(const QString& styleSheet, const QString& property, const QString& value);
    
private:
    static void setAttributeRecursive(QDomElement& elem,
                                      const QString& tagName,
                                      const QString& attribute,
                                      const QString& attributeValue);
};
