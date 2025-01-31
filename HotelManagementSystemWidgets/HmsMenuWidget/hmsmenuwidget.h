#pragma once

#include <QWidget>
#include <QFile>
#include <QListView>
#include <QLineEdit>
#include <QStandardItemModel>
#include <QEvent>

class HmsFocusWatcher : public QObject
{
    Q_OBJECT
    
public:
    explicit HmsFocusWatcher(QObject* parent = nullptr);
    
signals:
    void focusChanged(bool in);
    
protected:
    virtual bool eventFilter(QObject* obj, QEvent* event) override;
};

using HmsSection = std::pair<QString, QWidget*>;
using HmsSectionList = QList<HmsSection>;

namespace Ui {
class HmsMenuWidget;
}

class HmsMenuWidget : public QWidget
{
    Q_OBJECT

public:
    explicit HmsMenuWidget(QWidget* parent = nullptr, const HmsSectionList& sections = {});
    ~HmsMenuWidget() = default;
    
private slots:
    void menuItemHovered(const QModelIndex& index);
    void openMenu();
    void changeMenuIcon(bool inFocus);
    void changeSection(const QString& sectionName);

private:
    Ui::HmsMenuWidget* m_ui;
    HmsSectionList m_sections;
    
private:
    void initStyleSheet();
    void initSections();
    void initMenuComboBox();
};
