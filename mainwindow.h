#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"egg.h"
#include "map.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


    void initScene();

    QTimer e_Timer;
    //启动游戏  用于启动定时器对象
    void playGame();
    void Win();

    //更新坐标
    void updateMap();
    //绘图事件
    void paintEvent(QPaintEvent *event);
    //鼠标移动事件
    void mouseMoveEvent(QMouseEvent *event);
    //键盘移动事件
    void keyPressEvent(QKeyEvent *event);

    void startMusic();
    void gameMusic();
    void endmusic();

    //地图对象
    Map map;

    //蛋仔对象
    Egg eggBoy;

//三个按钮
private slots:
    void on_playButton_clicked();

    void on_quitButton_clicked();

    void on_restartButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
