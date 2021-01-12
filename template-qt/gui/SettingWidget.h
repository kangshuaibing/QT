#if _MSC_VER >=1600
#pragma execution_character_set("utf-8")
#endif
#ifndef SETTINGWIDGET_H
#define SETTINGWIDGET_H

#include <QWidget>

namespace Ui {
class SettingWidget;
}

class SettingWidget : public QWidget {
    Q_OBJECT

public:
    explicit SettingWidget(QWidget *parent = 0);
    ~SettingWidget();

private:
    Ui::SettingWidget *ui;
};

#endif // SETTINGWIDGET_H
