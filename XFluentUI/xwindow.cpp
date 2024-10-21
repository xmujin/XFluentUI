#include "xwindow.h"
#include <QPainter>
#include "xnavigationviewitem.h"
XWindow::XWindow(QWidget *parent)
    : QWidget{parent}
{

    resize(950, 750);
    setWindowFlag(Qt::WindowType::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);

    XNavigationViewItem *xnv = new XNavigationViewItem(this);

}


void XWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setBrush(QColor("#202022"));
    painter.setRenderHint(QPainter::Antialiasing, true);
    // painter.drawRect(rect());
    painter.drawRoundedRect(rect(), 20, 20);


}
