#ifndef CONFIG_H
#define CONFIG_H
//绝大部分用到的头文件
#include<QPixmap>
#include<QIcon>
#include <QMainWindow>
#include<QTimer>
#include<QPainter>
#include<QMouseEvent>
#include<QKeyEvent>
#include<QDebug>
#include <ctime>
#include<QSound>
#include<QMediaPlayer>

/**********  游戏配置数据 **********/

#define GAME_TITLE "蛋仔派对" //标题
#define GAME_ICON  ":/res/app.ico"

/**********  地图配置数据 **********/
#define MAP_WIDTH  1250 //宽度
#define MAP_HEIGHT 750//高度

//地图图片路径
#define MAP_PATH1  ":/res/ground1.jpg"
#define MAP_PATH2  ":/res/ground2.jpg"
#define MAP_PATH3  ":/res/terminal.jpg"
#define MAP_SCROLL_SPEED 2  //地图滚动速度
#define MAP_LENGTH 20
#define GAME_RATE  10   //刷新间隔，帧率 单位毫秒

/**********  蛋仔配置数据 **********/
#define EGG_RIGHT ":/res/egg_right.png"
#define EGG_LEFT ":/res/egg_left.png"
#define EGG_CRAWL ":/res/egg_crawl.png"
#define EGG_ROTATE ":/res/egg_rotate.png"

//跳跃速度
#define V_y 9

//重力加速度
#define GRAVITY 0.1













#endif // CONFIG_H
