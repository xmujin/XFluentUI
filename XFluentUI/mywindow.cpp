#include "mywindow.h"
#include <QGridLayout>
#include <QLabel>
#include "xnavigationview.h"
#include "xnavigationviewitem.h"
mywindow::mywindow(QWidget *parent)
    : QWidget{parent}
{

    setWindowTitle(tr("2D Painting on Native and OpenGL Widgets"));

    //XNavigationView *sb = new XNavigationView(this);
    //sb->setMinimumSize(200, 200);  // 设置最小尺寸
    //sb->setSizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);

    //XNavigationViewItem *sb = new XNavigationViewItem(this);



    //layout->addWidget(sb);

    QVBoxLayout *layout = new QVBoxLayout;
    QLabel *nativeLabel = new QLabel(tr("Native"));
    //nativeLabel->setAlignment(Qt::AlignHCenter);
    nativeLabel->setSizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);

    layout->addWidget(nativeLabel);
    setLayout(layout);

    resize(800, 600);
    adjustSize(); // 使父组件调整到合适的大小
    qDebug() << "all" << nativeLabel->width();

}
