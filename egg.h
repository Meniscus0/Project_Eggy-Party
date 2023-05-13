#ifndef EGG_H
#define EGG_H
#include"config.h"

class Egg
{
public:
    Egg();
    //鼠标设置蛋仔位置
    void setPosition(int x, int y);

    void jump();

    void update();

    void updateY();

    QPixmap changePic();

    //蛋仔资源 对象
    QPixmap right;    //右侧图片
    QPixmap left;     //左侧图片
    QPixmap crawl;    //飞扑图片
    QPixmap rotate;   //翻滚图片

    //蛋仔坐标
    int e_X;
    int e_Y;

    //蛋仔的矩形边框
    QRect m_Rect;

    bool m_isJumping=0;

    QTimer jump_Timer;
    //    下落速度
    double fall_speed=0;

    bool Right=0,Left=0,Crawl=0,Rotate=0;


};

#endif // EGG_H
