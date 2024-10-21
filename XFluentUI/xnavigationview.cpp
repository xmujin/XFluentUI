#include "xnavigationview.h"
#include "xnavigationviewitem.h"
#include <QMainWindow>
#include <QTreeWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QWidget>
#include <QStackedWidget>
#include <QLabel>
#include <QToolButton>
#include <QScreen>
#include <QLayout>
#include <QPropertyAnimation>
#include <QSplitter>
XNavigationView::XNavigationView(QWidget *parent)
    : QWidget{parent}
{




    indicator = new QFrame(this);
    indicator->setFrameShape(QFrame::Box);  // 设置为框形状
    indicator->setStyleSheet("background-color: blue;");  // 设置背景颜色为蓝色
    indicator->setFixedWidth(5);  // 蓝色条宽度
    indicator->setFixedHeight(37);  // 高度根据你的设计来调整
    //indicator->move(0, 0);  // 默认位置


    // 创建水平布局  包含左侧边导航栏以及右边栈页面
    hLayout = new QHBoxLayout(this);

    hLayout->setSpacing(0); // 按钮之间的间距为0
    hLayout->setContentsMargins(0, 0, 0, 0); // 所有边距为0

    // 创建垂直布局，包含左侧导航栏的所有子项
    sideNavigation = new QVBoxLayout();


    //创建栈页面
    stackedWidget = new QStackedWidget(this);


    sideNavigation->setSpacing(0); // 按钮之间的间距为0
    sideNavigation->setContentsMargins(0, 0, 0, 0); // 所有边距为0
    QSpacerItem *si = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);
    sideNavigation->addSpacerItem(si);


    // 将侧边栏和页面区域添加到主布局
    hLayout->addLayout(sideNavigation);
    hLayout->addWidget(stackedWidget);

    XNavigationViewItem *item1 = new XNavigationViewItem(this);

    QWidget *page1 = new QWidget();
    QWidget *page2 = new QWidget();

    QLabel *label1 = new QLabel("sdfsddddddddddddddddddddddsdfsd bfgydfstertxcvxc", page1);
    QLabel *label2 = new QLabel("sdfxcvbddddddddddddsdfsd bfgydfstertxcvxc", page2);

    QSplitter *splitter = new QSplitter(Qt::Horizontal);
    splitter->addWidget(page1);
    splitter->addWidget(page2);
    // 设置分割线（句柄）宽度
    splitter->setHandleWidth(1);  // 设置分割线宽度为5像素
    splitter->setStyleSheet("QSplitter::handle { background-color: blue; }");
    //splitter->setSizes(QList<int>() << 250 << 250);
    addNavigationItem(item1, splitter);
    //splitter->show();


    //XNavigationViewItem *item2 = new XNavigationViewItem(this);

    //addNavigationItem(item2, page2);

    //stackedWidget->setCurrentIndex(0);  // 确保设置了正确的索引

}


void XNavigationView::addNavigationItem(XNavigationViewItem *navigationViewItem, QWidget *page)
{
    sideNavigation->insertWidget(sideNavigation->count() - 1, navigationViewItem);
    stackedWidget->addWidget(page);
    indicator->raise();
    connect(navigationViewItem, &XNavigationViewItem::clicked, [=]() {
        // 指示器动画
        QPropertyAnimation *anim = new QPropertyAnimation(indicator, "pos", this);
        anim->setDuration(100);
        anim->setStartValue(indicator->pos());
        int src = stackedWidget->currentIndex();
        stackedWidget->setCurrentWidget(page);  // 切换到 page1
        int dest = stackedWidget->currentIndex();
        int delta = src - dest;
        anim->setEndValue(QPoint(0, indicator->pos().y() - delta * 40 ));
        anim->start();

    });
}

