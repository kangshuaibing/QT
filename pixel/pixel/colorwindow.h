#ifndef COLORWINDOW_H
#define COLORWINDOW_H

#include <QWidget>
#include <QToolButton>

class QGroupBox;
class ColorBarLight;
class ColorBarAlpha;
class ColorWindow : public QWidget
{
    Q_OBJECT
public:
    explicit ColorWindow(QWidget *parent = nullptr);

private:
    int chosenId;
    QToolButton* currentColorBtn;
    QString style[10];
    QToolButton* colorBtn[10];
    QGroupBox *btnGroup;
    QGroupBox *chosenColorGroup;
    ColorBarLight* colorbar1;
    ColorBarAlpha* colorbar2;
    QString getStyleSheet(const QColor& color);
    QString getStyleSheetAlpha(const QColor& color);


private slots:
    void changeColor(int);
    void changeColor(QColor);
    void changeColorLight(QColor);
    void changeColorAlpha(QColor);
    void colorDialog();

};

#endif // COLORWINDOW_H
