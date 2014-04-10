#include "widget.h"

Widget::Widget(QSystemTrayIcon *parent)
    : QSystemTrayIcon(parent),
      menu(new QMenu)
{
    setContextMenu(menu);
    setToolTip("HotVolume");
    setIcon(QIcon("://resource/Icon.jpg"));

    QAction * actQuit = new QAction("&Quit",this);
    connect(actQuit,SIGNAL(triggered()),qApp,SLOT(quit()));
    menu->addAction(actQuit);

    BASS_Init(-1,44100,BASS_DEVICE_DEFAULT,0,NULL);
    //BASS_SetVolume(0.0);
}

Widget::~Widget()
{

}
