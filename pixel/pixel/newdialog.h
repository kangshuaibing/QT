#ifndef NEWDIALOG_H
#define NEWDIALOG_H

#include <QWidget>

class QButtonGroup;
class QPushButton;
class QRadioButton;
class QLineEdit;
class QLabel;

class NewDialog : public QWidget
{
    Q_OBJECT
public:
    explicit NewDialog(QWidget *parent = nullptr);

private:
    QButtonGroup* radioGroup;
       QRadioButton* radio16;
       QRadioButton* radio32;
       QRadioButton* radio48;
       QRadioButton* radio64;
       QRadioButton* radioRandom;
       QPushButton* okBtn;
       QPushButton* cancelBtn;
       QLineEdit* startEdit;
       QLineEdit* finishEdit;
       QLabel* label1;
       QLabel* label2;


private slots:
    void newFile();
    void radioChange();
signals:
    void sendIndex(int,int);

public slots:
};

#endif // NEWDIALOG_H
