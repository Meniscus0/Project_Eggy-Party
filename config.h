#ifndef CONFIG_H
#define CONFIG_H

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
#define GAME_WIDTH  1250 //宽度
#define GAME_HEIGHT 750//高度
//#define GAME_WIDTH  768 //宽度
//#define GAME_HEIGHT 512//高度
#define GAME_TITLE "蛋仔派对 v1.0" //标题

#define GAME_ICON  ":/res/app.ico"

/**********  地图配置数据 **********/
#define MAP_PATH1  ":/res/ground1.jpg" //地图图片路径
#define MAP_PATH2  ":/res/ground2.jpg" //地图图片路径
#define MAP_PATH3  ":/res/terminal.jpg"
#define MAP_SCROLL_SPEED 2  //地图滚动速度

#define GAME_RATE  10   //刷新间隔，帧率 单位毫秒

/**********  飞机配置数据 **********/
#define HERO_RIGHT ":/res/egg_right.png"
#define HERO_LEFT ":/res/egg_left.png"
#define HERO_CRAWL ":/res/egg_crawl.png"
#define HERO_ROTATE ":/res/egg_rotate.png"

#define JUMP_SPEED 20

#define GRAVITY 10













#endif // CONFIG_H
