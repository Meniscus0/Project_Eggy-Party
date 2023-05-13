#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    //    设置窗口标题和图标
    w.setWindowTitle(GAME_TITLE);
    w.setWindowIcon(QIcon( GAME_ICON));
    return a.exec();
}
