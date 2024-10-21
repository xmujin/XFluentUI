#ifndef MYWINDOW_H
#define MYWINDOW_H

#include <QWidget>
#include "xnavigationview.h"
#include <QMouseEvent>
class mywindow : public QWidget
{
    Q_OBJECT
public:
    explicit mywindow(QWidget *parent = nullptr);

public:
    XNavigationView *xNavigationView;
protected:
    void mousePressEvent(QMouseEvent *event) override {
        if (event->button() == Qt::LeftButton) {
            // 记录鼠标按下的位置
            dragging = true;
            dragStartPos = event->globalPos() - frameGeometry().topLeft();
        }
    }

    void mouseMoveEvent(QMouseEvent *event) override {
        if (dragging) {
            // 移动窗口
            move(event->globalPos() - dragStartPos);
        }
    }

    void mouseReleaseEvent(QMouseEvent *event) override {
        if (event->button() == Qt::LeftButton) {
            dragging = false;
        }
    }
private:
    bool dragging = false;
    QPoint dragStartPos;

};

#endif // MYWINDOW_H
