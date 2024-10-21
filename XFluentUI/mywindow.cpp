#include "mywindow.h"
#include <QGridLayout>
#include <QLabel>
#include "xnavigationview.h"
#include <QPushButton>
mywindow::mywindow(QWidget *parent)
    : QWidget{parent}
{

    resize(800, 600);

    setWindowTitle(tr("Test X"));
    //setWindowFlags(Qt::FramelessWindowHint);
    setStyleSheet("background-color: #202022;  border-top-left-radius:15px;border-top-right-radius:5px;");


    xNavigationView = new XNavigationView();
    QLabel *nativeLabel = new QLabel(tr("Native"), this);
    nativeLabel->setAlignment(Qt::AlignHCenter);
    //nativeLabel->setSizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);


    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(xNavigationView);
    layout->addWidget(nativeLabel);
    setLayout(layout);

}


