#ifndef HOMESECTIONPAGE_H
#define HOMESECTIONPAGE_H

#include <QWidget>

namespace Ui {
class HomeSectionPage;
}

class HomeSectionPage : public QWidget
{
    Q_OBJECT

public:
    explicit HomeSectionPage(QWidget *parent = nullptr);
    ~HomeSectionPage();

private:
    Ui::HomeSectionPage *ui;
};

#endif // HOMESECTIONPAGE_H
