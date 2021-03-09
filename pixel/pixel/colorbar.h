#ifndef COLORBAR_H
#define COLORBAR_H


#include <QWidget>

class ColorBarLight:public QWidget
{
    Q_OBJECT
public:
    static QColor color;
    ColorBarLight(QWidget* parent = 0);
signals:
    void selectColor(QColor);
protected:
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *);
};


class ColorBarAlpha : public QWidget
{
    Q_OBJECT
public:
    static QColor color;
    ColorBarAlpha(QWidget* parent = 0);
signals:
    void selectColor(QColor);
protected:
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent*);
};


#endif // COLORBAR_H
