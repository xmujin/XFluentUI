#ifndef XNAVIGATIONVIEW_H
#define XNAVIGATIONVIEW_H

#include <QWidget>
#include <QFrame>
#include "xnavigationviewitem.h"
#include <QStackedWidget>
#include <QVBoxLayout>
class XNavigationView : public QWidget
{
    Q_OBJECT
public:
    explicit XNavigationView(QWidget *parent = nullptr);
    void addNavigationItem(XNavigationViewItem *navigationViewItem, QWidget *page);
signals:

private:
    QFrame *indicator;  // 蓝色滑动条
    QStackedWidget *stackedWidget; // 栈页面
    QVBoxLayout *sideNavigation;

};

#endif // XNAVIGATIONVIEW_H
