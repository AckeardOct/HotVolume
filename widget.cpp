#include "widget.h"

Widget::Widget(QSystemTrayIcon *parent)
    : QSystemTrayIcon(parent),
      menu(new QMenu)
{
    MyThread * thread = new MyThread;
    thread->start();
    setContextMenu(menu);
    setToolTip("HotVolume");
    setIcon(QPixmap("://resource/Icon.png"));

    QAction * actQuit = new QAction("&Quit",this);
    connect(actQuit,SIGNAL(triggered()),qApp,SLOT(quit()));
    menu->addAction(actQuit);
}

Widget::~Widget()
{

}
