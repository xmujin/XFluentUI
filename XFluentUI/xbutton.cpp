#include "xbutton.h"
#include <QPainter>
#include <QGraphicsDropShadowEffect>
XButton::XButton(QWidget *parent)
    : QPushButton{parent}
{

    //resize(200, 200);
    setFixedSize(100, 50);

}


void XButton::paintEvent(QPaintEvent *event)
{
    Q_D(XButton);



    QPainter painter(this);
    painter.setRenderHint(QPainter::RenderHint::Antialiasing); // 抗锯齿

    painter.save();
    QGraphicsDropShadowEffect *shadowEffect = new QGraphicsDropShadowEffect();


    //QColor shadowColor(0, 0, 0, 160); // 设置阴影颜色
    // painter.setBrush(QBrush(shadowColor));
    // painter.setRenderHint(QPainter::Antialiasing);
    // painter.drawRoundedRect(rect(), 1, 1);
    //QRect foregroundRect();

    painter.restore();




}
