#include "hmspopupwidget.h"
#include "ui_hmspopupwidget.h"

HmsPopupWidget::HmsPopupWidget(QWidget *parent)
    : QWidget{ parent }
    , m_ui{ new Ui::HmsPopupWidget }
    , m_topLayout{ new QHBoxLayout{} }
    , m_bodyLayout{ new QVBoxLayout{} }
    , m_footerLayout{ new QHBoxLayout{} }
    , m_bottomLayout{ new QHBoxLayout{} }
{
    m_ui->setupUi(this);
    
    m_topLayout->setObjectName("topLayout");
    m_ui->gridLayout->addLayout(m_topLayout, 0, 0);
    
    m_bodyLayout->setObjectName("bodyLayout");
    m_ui->gridLayout->addLayout(m_bodyLayout, 1, 0);
    
    m_footerLayout->setObjectName("footerLayout");
    m_ui->gridLayout->addLayout(m_footerLayout, 2, 0);
    
    m_bottomLayout->setObjectName("bottomLayout");
    m_ui->gridLayout->addLayout(m_bottomLayout, 3, 0);
    
    setAttribute(Qt::WA_TranslucentBackground);
    setAttribute(Qt::WA_DeleteOnClose);
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    setWindowModality(Qt::ApplicationModal);
}

void HmsPopupWidget::exec()
{
    if (!parent())
        return;
    
    for (auto* parentWidget : this->parent()->findChildren<QWidget*>())
    {
        if (parentWidget == this || this->findChildren<QWidget*>().contains(parentWidget))
            continue;
        
        parentWidget->setEnabled(false);
        auto* effect = new QGraphicsOpacityEffect{};
        effect->setOpacity(0.2);
        parentWidget->setGraphicsEffect(effect);
    }
    
    adjustSize();
    updateGeometry();
    
    setGeometry(15, 15, width(), height());
    
    this->show();
}

void HmsPopupWidget::close()
{
    if (!parent())
        return;
    
    for (auto* parentWidget : this->parent()->findChildren<QWidget*>())
    {
        parentWidget->setEnabled(true);
        auto* effect = new QGraphicsOpacityEffect{};
        effect->setOpacity(1);
        parentWidget->setGraphicsEffect(effect);
    }
}

HmsPopupWidget* HmsPopupWidget::setTitle(const QString& title)
{
    auto *existingTitle = this->findChild<QLabel*>("titleLabel");
    if (existingTitle == nullptr)
    {
        auto titleLabel = new QLabel{ title };
        titleLabel->setObjectName("titleLabel");
        titleLabel->setFont(HmsUiHelper::Regular_Bold_Font);
        titleLabel->setStyleSheet(QString{ "background: transparent;" });
        
        m_topLayout->addWidget(titleLabel, 0, m_topLayout->children().isEmpty() ? Qt::AlignmentFlag::AlignHCenter : Qt::AlignmentFlag::AlignRight);
    }
    else
    {
        existingTitle->setText(title);
    }
    
    changeTitleColor();
    
    updateGeometry();
    
    return this;
}

HmsPopupWidget* HmsPopupWidget::setButtons(const HmsPopupButtonsFlags& buttons)
{
    for (const auto& widget : m_bottomLayout->findChildren<QWidget*>())
        m_bottomLayout->removeWidget(widget);
    
    if (buttons & HmsPopupButtons::Back) {
        auto* backButton = createButton("Back");
        backButton->setObjectName("backButton");
        m_topLayout->addWidget(backButton, 0, Qt::AlignmentFlag::AlignLeft);
    }
    if (buttons & HmsPopupButtons::Cancel) {
        auto* cancelButton = createButton("Cancel");
        cancelButton->setObjectName("cancelButton");
        m_bottomLayout->addWidget(cancelButton);
    }
    if (buttons & HmsPopupButtons::Remove) {
        auto* removeButton = createButton("Remove");
        removeButton->setObjectName("removeButton");
        m_bottomLayout->addWidget(removeButton);
    }
    if (buttons & HmsPopupButtons::Refresh) {
        auto* refreshButton = createButton("Refresh");
        refreshButton->setObjectName("refreshButton");
        m_bottomLayout->addWidget(refreshButton);
    }
    if (buttons & HmsPopupButtons::Save) {
        auto* saveButton = createButton("Save");
        saveButton->setObjectName("saveButton");
        m_bottomLayout->addWidget(saveButton);
    }
    if (buttons & HmsPopupButtons::Confirm) {
        auto* confirmButton = createButton("Confirm");
        confirmButton->setObjectName("confirmButton");
        m_bottomLayout->addWidget(confirmButton);
    }
    
    return this;
}

QPushButton* HmsPopupWidget::getButton(const HmsPopupButtons& button)
{
    switch(button) {
    case HmsPopupButtons::Back : return findChild<QPushButton*>("backButton");
    case HmsPopupButtons::Cancel : return findChild<QPushButton*>("cancelButton");
    case HmsPopupButtons::Remove : return findChild<QPushButton*>("removeButton");
    case HmsPopupButtons::Refresh : return findChild<QPushButton*>("refreshButton");
    case HmsPopupButtons::Save : return findChild<QPushButton*>("saveButton");
    case HmsPopupButtons::Confirm : return findChild<QPushButton*>("confirmButton");
    default : return nullptr;
    }
}

HmsPopupWidget* HmsPopupWidget::setTitleType(const HmsPopupTitles& titleType)
{
    m_titleType = titleType;
    changeTitleColor();
    
    return this;
}

HmsPopupWidget* HmsPopupWidget::setFooterTitle(const QString& title)
{
    auto *existingTitle = this->findChild<QLabel*>("footerTitleLabel");
    if (existingTitle == nullptr)
    {   
        auto footerTitleLabel = new QLabel{ title };
        footerTitleLabel->setObjectName("footerTitleLabel");
        footerTitleLabel->setFont(HmsUiHelper::Small_Title_Font);
        footerTitleLabel->setStyleSheet(QString{ "color: #003049;" });
        m_footerLayout->addWidget(footerTitleLabel, 0, Qt::AlignmentFlag::AlignHCenter);
    }
    else
    {
        existingTitle->setText(title);
    }
    
    return this;
}

HmsPopupWidget* HmsPopupWidget::addInfoRows(const QList<QStringList>& values, bool centering)
{
    auto *existingTableView = this->findChild<QLabel*>("infoTableView");
    
    if (existingTableView != nullptr)
        m_bodyLayout->removeWidget(existingTableView);
    
    auto* infoTableView = new QTableView{};
    infoTableView->setObjectName("infoTableView");
    
    infoTableView->horizontalHeader()->hide();
    infoTableView->horizontalHeader()->setStretchLastSection(true);
    infoTableView->verticalHeader()->hide();
    infoTableView->setEditTriggers(QTableView::NoEditTriggers);
    
    auto* infoTableModel = new QStandardItemModel{};
    
    for (const auto& row : values)
    {
        QList<QStandardItem*> infoRowItems;
        for (const auto& value : row)
        {
            auto* item = new QStandardItem{ value };
            if (centering)
                item->setData(Qt::AlignHCenter, Qt::TextAlignmentRole);
            infoRowItems.append(item);
        }
        infoTableModel->appendRow(infoRowItems);
    }
    infoTableView->setModel(infoTableModel);
    
    infoTableView->setFont(HmsUiHelper::Regular_Font);
    infoTableView->setStyleSheet("color: #C1121F; background-color: transparent;");
    
    infoTableView->resizeColumnsToContents();
    infoTableView->resizeRowsToContents();
    
    m_bodyLayout->addWidget(infoTableView, Qt::AlignmentFlag::AlignHCenter);
    
    return this;
}

HmsPopupWidget* HmsPopupWidget::addLineEdit(QLineEdit* lineEdit)
{
    m_bodyLayout->addWidget(lineEdit);
    return this;
}

QLineEdit* HmsPopupWidget::getLineEdit(const QString& objectName)
{
    return findChild<QLineEdit*>(objectName);
}

HmsPopupWidget* HmsPopupWidget::addRateSystem()
{   
    return this;
}

void HmsPopupWidget::paintEvent(QPaintEvent* event)
{
    QRect roundedRect;
    roundedRect.setX(rect().x() + 5);
    roundedRect.setY(rect().y() + 5);
    roundedRect.setWidth(rect().width() - 10);
    roundedRect.setHeight(rect().height() - 10);
    
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(QPen(QColor{ 120, 0, 0 }, 2));
    painter.setBrush(QBrush{ QColor{ 253, 240, 213 } });
    painter.drawRoundedRect(roundedRect, 5, 5);
}

void HmsPopupWidget::changeTitleColor()
{
    auto* existingTitle = this->findChild<QLabel*>("titleLabel");
    
    if (existingTitle == nullptr)
        return;
    
    QString color{ "#000000" };
    if (m_titleType == HmsPopupTitles::Common)
        color = "#C1121F";
    else if (m_titleType == HmsPopupTitles::Success)
        color = "#669BBC";
    
    existingTitle->setStyleSheet(HmsUiHelper::changeStyleSheetProperty(existingTitle->styleSheet(), "color", color));
}

QPushButton* HmsPopupWidget::createButton(const QString& text)
{
    auto* button = new QPushButton{ text };
    button->setFont(HmsUiHelper::Regular_Font);
    button->setStyleSheet("color: #FFFFFF; background-color: #003049; border: 1px none; border-radius: 3;");
    
    return button;
}
