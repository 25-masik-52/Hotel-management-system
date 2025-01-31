#include "hmsmenuwidget.h"
#include "ui_hmsmenuwidget.h"

HmsFocusWatcher::HmsFocusWatcher(QObject* parent)
    : QObject{ parent }
{
    if (parent)
        parent->installEventFilter(this);
}

bool HmsFocusWatcher::eventFilter(QObject* obj, QEvent* event)
{
    Q_UNUSED(obj)
    
    if (event->type() == QEvent::FocusIn)
        emit focusChanged(true);
    else if (event->type() == QEvent::FocusOut)
        emit focusChanged(false);
    
    return false;
}

HmsMenuWidget::HmsMenuWidget(QWidget* parent, const HmsSectionList& sections)
    : QWidget{ parent }
    , m_ui{ new Ui::HmsMenuWidget }
    , m_sections{ sections }
{
    m_ui->setupUi(this);
    
    initStyleSheet();
    initSections();
    initMenuComboBox();
    
    connect(m_ui->menuButton, &QPushButton::clicked,
            this, &HmsMenuWidget::openMenu);
}

void HmsMenuWidget::menuItemHovered(const QModelIndex& index)
{
    auto* model = static_cast<QStandardItemModel*>(m_ui->menuComboBox->model());
    
    if (!model)
    {
        qCritical() << "[HmsMenuWidget::menuItemHovered] No model found!";
        return;
    }
    
    QFont font{ "TT Wellingtons" };
    font.setPixelSize(20);
    
    for (int i = 0; i < model->rowCount(); ++i)
    {
        auto tempIndex = model->index(i, 0);
        
        auto weight = tempIndex == index ? QFont::Bold : QFont::Medium;
        auto underline = tempIndex == index ? true : false;
        
        font.setWeight(weight);
        font.setUnderline(underline);
        
        model->setData(tempIndex, font, Qt::FontRole);
    }
}

void HmsMenuWidget::openMenu()
{
    m_ui->menuComboBox->showPopup();
    m_ui->menuComboBox->view()->window()->setFocus();
}

void HmsMenuWidget::changeMenuIcon(bool inFocus)
{
    if (!inFocus)
        menuItemHovered({});
    m_ui->menuButton->setIcon(QIcon{ m_ui->menuButton->icon().pixmap(m_ui->menuButton->size()).transformed(QTransform{}.rotate(90)) });
}

void HmsMenuWidget::changeSection(const QString& sectionName)
{
    const auto senctionIter = std::find_if(m_sections.begin(), m_sections.end(),
                                           [&sectionName] (const HmsSection& section) {
                                               return section.first == sectionName;
                                           });
    if (senctionIter == m_sections.end())
    {
        qCritical() << QString{ "[HmsMenuWidget::changeSection] No section with such name: %1!" }.arg(sectionName);
        return;
    }
    
    m_ui->stackedWidget->setCurrentWidget(senctionIter->second);
}

void HmsMenuWidget::initStyleSheet()
{
    QFile qssFile{ ":/hms_menu_qss/assets/qss/menu_main.qss" };
    if (qssFile.open(QFile::ReadOnly))
        this->setStyleSheet(QLatin1String{ qssFile.readAll() });
    else
        qCritical() << QString{ "[HmsMenuWidget::initStyleSheet] Couldn`t open %1!" }.arg(qssFile.fileName());
}

void HmsMenuWidget::initSections()
{
    for (const auto& section : m_sections)
    {
        if (section.first.isEmpty() || section.second == nullptr)
            continue;
        
        m_ui->menuComboBox->addItem(section.first);
        m_ui->stackedWidget->addWidget(section.second);
    }
}

void HmsMenuWidget::initMenuComboBox()
{
    auto* menuComboBoxListView = new QListView{ m_ui->menuComboBox };
    m_ui->menuComboBox->setView(menuComboBoxListView);
    
    auto* view = m_ui->menuComboBox->view();
    if (!view)
    {
        qCritical() << "[HmsMenuWidget::initMenuComboBox] No ComboBoxView found!";
        return;
    }
    
    auto popup = view->window();
    if (!popup)
    {
        qCritical() << "[HmsMenuWidget::initMenuComboBox] No ComboBoxPopup found!";
        return;
    }
    popup->setAttribute(Qt::WA_TranslucentBackground, true);
    
    auto* menuComboBoxLineEdit = new QLineEdit{ m_ui->menuComboBox };
    menuComboBoxLineEdit->setReadOnly(true);
    menuComboBoxLineEdit->setAlignment(Qt::AlignHCenter);
    
    m_ui->menuComboBox->setEditable(true);
    m_ui->menuComboBox->setLineEdit(menuComboBoxLineEdit);
    
    for(int i = 0; i < m_ui->menuComboBox->count(); ++i)
        m_ui->menuComboBox->setItemData(i, Qt::AlignCenter, Qt::TextAlignmentRole);
    
    connect(m_ui->menuComboBox->view(), &QAbstractItemView::entered,
            this, &HmsMenuWidget::menuItemHovered);
    connect(m_ui->menuComboBox, qOverload<const QString&>(&QComboBox::currentTextChanged),
            this, &HmsMenuWidget::changeSection);
    connect(new HmsFocusWatcher{ popup }, &HmsFocusWatcher::focusChanged,
            this, &HmsMenuWidget::changeMenuIcon);
}
