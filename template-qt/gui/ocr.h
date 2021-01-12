#if _MSC_VER >=1600
#pragma execution_character_set("utf-8")
#endif
#ifndef OCR_H
#define OCR_H

#include <QWidget>
#include "imagewidget.h"
#include "bean/ocrtablemodel.h"

namespace Ui {
class OCR;
}

class OCR : public QWidget
{
    Q_OBJECT

public:
    explicit OCR(QWidget *parent = 0);
    ~OCR();
    ImageWidget *m_Image;
    OCRTableModel *ocrTableModel;

private:
    Ui::OCR *ui;
    void initializeUi(); // 初始化 Ui
};

#endif // OCR_H
