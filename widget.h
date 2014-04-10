#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QSystemTrayIcon>
#include <QMenu>
#include <QAction>
#include <QApplication>
#include <QThread>
#include <QDebug>
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
private:
    float volumeBackUp;
public:
    void run()
    {
        RegisterHotKey(NULL,1,MOD_ALT,Qt::Key_Z);
        RegisterHotKey(NULL,2,MOD_ALT,Qt::Key_A);
        RegisterHotKey(NULL,3,MOD_ALT,Qt::Key_S);
        QApplication::processEvents();

        MSG msg;
        while(GetMessage(&msg,NULL,0,0))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
            if (msg.message == WM_HOTKEY)
            {
                BASS_Init(-1,44100,BASS_DEVICE_DEFAULT,0,NULL);
                if (msg.wParam == 1)
                {
                    volumeBackUp = BASS_GetVolume() == 0 ? volumeBackUp : BASS_GetVolume();
                    BASS_SetVolume(BASS_GetVolume() != 0 ? 0 : volumeBackUp);
                }
                else if (msg.wParam == 2)
                {
                    BASS_SetVolume(BASS_GetVolume() + 0.1);
                }
                else if (msg.wParam == 3)
                {
                    BASS_SetVolume(BASS_GetVolume() - 0.1);
                }
            }
        }


        exec();
    }
};

#endif // WIDGET_H
