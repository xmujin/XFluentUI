#include "mywindow.h"

#include <QApplication>
#include <QPushButton>
#include <QVBoxLayout>
#include "xwindow.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // mywindow w;
    // w.show();
    XWindow w;
    w.show();

    return a.exec();
}
