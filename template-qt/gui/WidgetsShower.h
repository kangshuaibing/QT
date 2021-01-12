#if _MSC_VER >=1600
#pragma execution_character_set("utf-8")
#endif
#ifndef WIDGETSSHOWER_H
#define WIDGETSSHOWER_H

#include <QWidget>

namespace Ui {
class WidgetsShower;
}

/**
 * 展示多个 widgets 的效果
 */
class WidgetsShower : public QWidget {
    Q_OBJECT

public:
    explicit WidgetsShower(QWidget *parent = 0);
    ~WidgetsShower();

private:
    Ui::WidgetsShower *ui;
};

#endif // WIDGETSSHOWER_H
