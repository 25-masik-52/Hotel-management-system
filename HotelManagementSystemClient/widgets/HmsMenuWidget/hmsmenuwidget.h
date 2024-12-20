#ifndef HMSMENUWIDGET_H
#define HMSMENUWIDGET_H

#include <QWidget>

namespace Ui {
class HmsMenuWidget;
}

class HmsMenuWidget : public QWidget
{
    Q_OBJECT

public:
    explicit HmsMenuWidget(QWidget *parent = nullptr);
    ~HmsMenuWidget();

private:
    Ui::HmsMenuWidget *ui;
};

#endif // HMSMENUWIDGET_H
