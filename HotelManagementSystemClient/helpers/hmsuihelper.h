#pragma once

#include <QWidget>
#include <QIcon>
#include <QFile>
#include <QPainter>
#include <QSvgRenderer>
#include <QDomDocument>
#include <QRegularExpression>
#include <QGraphicsDropShadowEffect>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>

class HmsUiHelper
{    
public:
    static const QColor HMS_COLOR_RED;
    static const QColor HMS_COLOR_DARK_BLUE;
    
    static const int HMS_ACTION_ICON_DEFAULT_SIZE;
    
    static const QString HMS_ICON_CLOSED_EYE;
    static const QString HMS_ICON_OPENED_EYE;
    
    static void setStyleSheet(QWidget* widget);
    static QString changeStyleSheetProperty(const QString& styleSheet, const QString& property, const QString& value);
    static QIcon createIconFromSvg(const QString& svgFilePath, const QColor& color, int width = HMS_ACTION_ICON_DEFAULT_SIZE, int height = HMS_ACTION_ICON_DEFAULT_SIZE);
    
private:
    static const QMap<QString, QString> m_qssFiles;
};
