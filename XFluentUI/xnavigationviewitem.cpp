#include "xnavigationviewitem.h"
#include <QPainter>
#include <QEvent>
#include <QPushButton>
#include <QScreen>
XNavigationViewItem::XNavigationViewItem(QWidget *parent)
    : QAbstractButton{parent}, hover{false}
{
    QRect screenRect = QGuiApplication::primaryScreen()->geometry();
    setSizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
    setFixedSize(screenRect.width() * 0.15, screenRect.width() * 0.15 * 0.135);
    setSizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
    setFixedSize(screenRect.width() * 0.15, screenRect.width() * 0.15 * 0.135);

}

XNavigationViewItem::XNavigationViewItem(const QString &text, QWidget *parent)
    : QAbstractButton{parent}, hover{false}
{

}


void XNavigationViewItem::paintEvent(QPaintEvent *)
{
    QPainter painter(this);


    // 先判断是否按下
    if (this->isDown())
    {
        painter.setBrush(QColor("#e0e0e0"));  // 按下时的颜色
    }
    else if (this->isHover())
    {
        painter.setBrush(QColor("#f5f5f5"));  // 悬停时的颜色
    }
    else
    {
        painter.setBrush(QColor("#ffffff"));  // 默认颜色
    }
    painter.setPen(Qt::NoPen);
    painter.drawRect(rect());


    painter.setPen(Qt::black);

    // 设置字体
    QFont font("Segoe UI", 16); // 字体名称和大小
    painter.setFont(font);
    painter.setRenderHint(QPainter::RenderHint::Antialiasing);
    painter.drawText(0,0,this->width(),this->height(),Qt::AlignCenter,"123ABC一二三");


}

bool XNavigationViewItem::event(QEvent *e)
{
    if(e->type() == QEvent::HoverEnter)
    {
        setHover(true);
    }
    else if(e->type() == QEvent::HoverLeave)
    {
        setHover(false);
    }

    return QAbstractButton::event(e);
}





// void XNavigationViewItem::mousePressEvent(QMouseEvent *e)
// {
//     QAbstractButton::mousePressEvent(e);
// }

// void XNavigationViewItem::enterEvent(QEnterEvent *e)
// {
//     //emit clicked();
//     //QToolButton::enterEvent(e);
// }


