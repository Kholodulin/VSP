#include "movesquare.h"
moveSquare::moveSquare(QWidget *parent)
    : QWidget(parent)
{
    setAttribute(Qt::WA_StaticContents);
}
void moveSquare::paintEvent(QPaintEvent* e){
    Q_UNUSED(e);;
    drawR();
}
void moveSquare::drawR(){
    QPainter paint(this);
    paint.setBrush(QBrush(Qt::green));
    paint.drawRect(lastPoint.rx(),lastPoint.ry(), widthSq, heightSq);
    update();
}

void moveSquare::mousePressEvent(QMouseEvent* e){
    if (e->button() == Qt::LeftButton && lastPoint.rx()<e->position().rx() && lastPoint.rx()+widthSq>e->position().rx()
            && lastPoint.ry()<e->position().ry() && lastPoint.ry()+heightSq>e->position().ry()) {
        mousePoint= lastPoint-e->pos();
        scribbling = true;
    }
}
void moveSquare::mouseMoveEvent(QMouseEvent* e){
    if ((e->buttons() & Qt::LeftButton) && scribbling){
        lastPoint=(e->position().toPoint()+mousePoint);
    }
}
void moveSquare::mouseReleaseEvent(QMouseEvent* e){
    if (e->button() == Qt::LeftButton && scribbling) {
        lastPoint=(e->position().toPoint()+mousePoint);
        scribbling = false;
    }
}
