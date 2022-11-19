#ifndef SQUARE_H
#define SQUARE_H

#include <QWidget>
#include <QPainter>
#include <QPaintEvent>
#include <QMouseEvent>
#include <QEvent>
#include <QPointF>



class moveSquare : public QWidget
{

public:
    moveSquare(QWidget *parent = nullptr);
    void drawR();

protected:
    void paintEvent(QPaintEvent* e) override;
    void mousePressEvent(QMouseEvent* e) override;
    void mouseMoveEvent(QMouseEvent* e) override;
    void mouseReleaseEvent(QMouseEvent* e) override;
private:
    bool scribbling = false;
    QPointF lastPoint{0,0};
    QPointF mousePoint;
    int widthSq = 120;
    int heightSq = 120;
};
#endif // SQUARE_H
