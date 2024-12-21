#pragma once

#include "../../helpers/hmsuihelper.h"
#include <QWidget>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QPainter>
#include <QLabel>
#include <QTableView>
#include <QStandardItem>
#include <QHeaderView>
#include <QGraphicsOpacityEffect>

namespace Ui {
class HmsPopupWidget;
enum class HmsPopupButtons;
enum class HmsPopupTitles;
}

enum class HmsPopupButtons
{
    Back = 1 << 0,
    Cancel = 1 << 1,
    Confirm = 1 << 2,
    Save = 1 << 3,
    Refresh = 1 << 4,
    Remove = 1 << 5
};

Q_DECLARE_FLAGS(HmsPopupButtonsFlags, HmsPopupButtons)
Q_DECLARE_OPERATORS_FOR_FLAGS(HmsPopupButtonsFlags)

enum class HmsPopupTitles
{
    Common,
    Success
};

class HmsPopupWidget : public QWidget
{
    Q_OBJECT

public:
    explicit HmsPopupWidget(QWidget *parent);
    ~HmsPopupWidget() = default;
    
public:
    void exec();
    void close();
    
    HmsPopupWidget* setTitle(const QString& title);
    HmsPopupWidget* setButtons(const HmsPopupButtonsFlags& buttons);
    QPushButton* getButton(const HmsPopupButtons& button);
    HmsPopupWidget* setTitleType(const HmsPopupTitles& titleType);
    HmsPopupWidget* setFooterTitle(const QString& title);
    HmsPopupWidget* addInfoRows(const QList<QStringList>& values, bool centering = false);
    HmsPopupWidget* addLineEdit(QLineEdit* lineEdit);
    QLineEdit* getLineEdit(const QString& objectName);
    HmsPopupWidget* addRateSystem();
    
protected:
    void paintEvent(QPaintEvent* event) override;

private:
    Ui::HmsPopupWidget* m_ui;
    QHBoxLayout* m_topLayout;
    QVBoxLayout* m_bodyLayout;
    QHBoxLayout* m_footerLayout;
    QHBoxLayout* m_bottomLayout;
    
    HmsPopupTitles m_titleType{ HmsPopupTitles::Common };
    
private:
    void changeTitleColor();
    QPushButton* createButton(const QString& text);
};
