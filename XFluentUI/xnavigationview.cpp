#include "xnavigationview.h"
#include "xnavigationviewitem.h"
#include <QApplication>
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
XNavigationView::XNavigationView(QWidget *parent)
    : QWidget{parent}, sideNavigation{new QVBoxLayout()}
{
    setSizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
    setMinimumSize(700,500);

    QWidget *horizontalLayoutWidget = new QWidget(this);
    stackedWidget = new QStackedWidget(horizontalLayoutWidget);
    // 创建主布局  包含左侧边导航栏以及右边栈页面
    QHBoxLayout *hLayout = new QHBoxLayout(horizontalLayoutWidget);

    QRect screenRect = QGuiApplication::primaryScreen()->geometry();
    int screenW = screenRect.width();
    int screenH = screenRect.height();
    qDebug()<<"窗口位置："<<"屏幕宽度:\t"<<screenW<<"屏幕高度:\t"<<screenH;//必须包含相关的头文件


    sideNavigation->setSpacing(0); // 按钮之间的间距为0
    sideNavigation->setContentsMargins(0, 0, 0, 0); // 所有边距为0
    QSpacerItem *si = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);
    sideNavigation->addSpacerItem(si);


    // 将侧边栏和页面区域添加到主布局

    hLayout->addLayout(sideNavigation);
    hLayout->addWidget(stackedWidget);
    // 连接导航项的点击事件
    // connect(treeWidget, &QTreeWidget::itemClicked, [=](QTreeWidgetItem *item, int) {
    //     int index = treeWidget->indexOfTopLevelItem(item);
    //     stackedWidget->setCurrentIndex(index);
    // });

    //setLayout(hLayout);

    stackedWidget->setMinimumWidth(300);
    stackedWidget->setMinimumHeight(200);

    stackedWidget->setSizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);

    //stackedWidget->setFixedHeight(300);
    //stackedWidget->setFixedWidth(300);

    XNavigationViewItem *sb = new  XNavigationViewItem(horizontalLayoutWidget);
    QWidget *page1 = new QWidget();

    QLabel *dd = new QLabel(tr("sdfsddddddddddddddddddddddsdfsd bfgydfstertxcvxc"), page1);
    addNavigationItem(sb, page1);


    XNavigationViewItem *sb1 = new  XNavigationViewItem(horizontalLayoutWidget);

    addNavigationItem(sb1, new QLabel(tr("sdfsdfs")));

    stackedWidget->setCurrentIndex(0);  // 确保设置了正确的索引


    QSize stackedSize = stackedWidget->size();
    int width = stackedSize.width();    // 获取宽度
    int height = stackedSize.height();  // 获取高度
    qDebug() << "fule" << width;
    qDebug() << "fule" << height;
    dd->setGeometry(QRect(0, 0, 300, 50));
    qDebug() << "fule" << page1->width();
    qDebug() << "fule" << page1->height();

    qDebug() << "horizontalLayoutWidget" << horizontalLayoutWidget->width();
    qDebug() << "horizontalLayoutWidget" << horizontalLayoutWidget->height();

    qDebug() << "this" << this->rect().width();
    qDebug() << "this" << this->rect().height();

}


void XNavigationView::addNavigationItem(XNavigationViewItem *navigationViewItem, QWidget *page)
{
    //sideNavigation->insertItem(sideNavigation->count() - 1, );
    sideNavigation->insertWidget(sideNavigation->count() - 1, navigationViewItem);
    stackedWidget->addWidget(page);

    connect(navigationViewItem, &XNavigationViewItem::clicked, [=]() {
        stackedWidget->setCurrentWidget(page);  // 切换到 page1
        qDebug() << "fule";
    });
}

