#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    BASS_Init(-1,44100,BASS_DEVICE_DEFAULT,0,NULL);
    BASS_SetVolume(0.0);
}

Widget::~Widget()
{

}
