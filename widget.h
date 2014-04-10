#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QSystemTrayIcon>
#include <QMenu>
#include <QAction>
#include <QApplication>
#include <bass.h>

class Widget : public QSystemTrayIcon
{
    Q_OBJECT
private:
    QMenu * menu;

public:
    Widget(QSystemTrayIcon *parent = 0);
    ~Widget();
};

#endif // WIDGET_H
