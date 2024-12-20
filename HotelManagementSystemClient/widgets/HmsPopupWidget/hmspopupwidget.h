#ifndef HMSPOPUPWIDGET_H
#define HMSPOPUPWIDGET_H

#include <QWidget>

namespace Ui {
class HmsPopupWidget;
}

class HmsPopupWidget : public QWidget
{
    Q_OBJECT

public:
    explicit HmsPopupWidget(QWidget *parent = nullptr);
    ~HmsPopupWidget();

private:
    Ui::HmsPopupWidget *ui;
};

#endif // HMSPOPUPWIDGET_H
