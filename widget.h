#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QSystemTrayIcon>
#include <QMenu>
#include <QAction>
#include <QApplication>
#include <QThread>
#include <bass.h>
#include <windows.h>

class Widget : public QSystemTrayIcon
{
    Q_OBJECT
private:
    QMenu * menu;

public:
    Widget(QSystemTrayIcon *parent = 0);
    ~Widget();
};

class MyThread : public QThread
{
    Q_OBJECT
public:
    void run()
    {
        RegisterHotKey(NULL,1,MOD_ALT,Qt::Key_Z);
        RegisterHotKey(NULL,2,MOD_ALT,Qt::Key_X);
        QApplication::processEvents();

        MSG msg;
        while(GetMessage(&msg,NULL,0,0))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
            if (msg.message == WM_HOTKEY)
            {
                if (msg.wParam == 1)
                {
                    BASS_Init(-1,44100,BASS_DEVICE_DEFAULT,0,NULL);
                    BASS_SetVolume(0.0);
                }
                else if (msg.wParam == 2)
                {
                    BASS_Init(-1,44100,BASS_DEVICE_DEFAULT,0,NULL);
                    BASS_SetVolume(1.0);
                }
            }
        }


        exec();
    }
};

#endif // WIDGET_H
