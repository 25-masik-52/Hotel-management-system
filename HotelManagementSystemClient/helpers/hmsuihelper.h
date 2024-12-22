#pragma once

#include <QWidget>
#include <QIcon>
#include <QFile>
#include <QPainter>
#include <QSvgRenderer>
#include <QDomDocument>
#include <QRegularExpression>
#include <QGraphicsDropShadowEffect>

class HmsUiHelper
{
public:
    static const QFont Regular_Font;
    static const QFont Regular_Bold_Font;
    static const QFont Title_Regular_Font;
    
    static const QColor Accent_Color;
    static const QColor Info_Color;
    static const QColor Background_Color;
    static const QColor Control_Color;
    static const QColor Control_Info_Color;
    static const QColor MediumPassword_Color;
    static const QColor HardPassword_Color;
    
public:
    static QIcon createIconFromSvg(const QString &svgFilePath, const QColor &color, int width, int height);
    static QString changeStyleSheetProperty(const QString& styleSheet, const QString& property, const QString& value);
    static void setButtonDropShadow(QWidget* widget);
    static void setLineEditInnerShadow(QWidget* widget);
    
private:
    static void setAttributeRecursive(QDomElement& elem,
                                      const QString& tagName,
                                      const QString& attribute,
                                      const QString& attributeValue);
};
