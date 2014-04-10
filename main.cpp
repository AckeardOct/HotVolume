#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    MyThread myThread;
    w.show();
    myThread.start();
    return a.exec();
}
