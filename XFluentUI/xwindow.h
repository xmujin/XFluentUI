#ifndef XWINDOW_H
#define XWINDOW_H

#include <QWidget>

class XWindow : public QWidget
{
    Q_OBJECT
public:
    explicit XWindow(QWidget *parent = nullptr);



protected:
    // Event handlers
    // bool event(QEvent *event) override;
    // virtual void mousePressEvent(QMouseEvent *event);
    // virtual void mouseReleaseEvent(QMouseEvent *event);
    // virtual void mouseDoubleClickEvent(QMouseEvent *event);
    // virtual void mouseMoveEvent(QMouseEvent *event);

    // virtual void keyPressEvent(QKeyEvent *event);
    // virtual void keyReleaseEvent(QKeyEvent *event);
    // virtual void focusInEvent(QFocusEvent *event);
    // virtual void focusOutEvent(QFocusEvent *event);
    // virtual void enterEvent(QEnterEvent *event);
    // virtual void leaveEvent(QEvent *event);
    virtual void paintEvent(QPaintEvent *event);
    // virtual void moveEvent(QMoveEvent *event);
    // virtual void resizeEvent(QResizeEvent *event);
    // virtual void closeEvent(QCloseEvent *event);
};

#endif // XWINDOW_H
