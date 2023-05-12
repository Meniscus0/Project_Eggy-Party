#ifndef EGG_H
#define EGG_H
#include"config.h"

class Egg
{
public:
    Egg();
    //设置飞机位置
    void setPosition(int x, int y);

    void jump();

    void update();

    void updateY();

    QPixmap getImg();

//    void Egg::endmusic();

    //蛋仔资源 对象
    QPixmap m_Plane;
    QPixmap right;  //右侧图片
    QPixmap left;     //左侧图片
    QPixmap crawl;  //前扑图片
    QPixmap rotate;     //翻滚图片

    //蛋仔坐标
    int m_X;
    int m_Y;

    int m_jumpSpeed;
    //蛋仔的矩形边框
    QRect m_Rect;

    bool m_isJumping=0;
    QTimer jump_Timer;

    double fall_speed;

    bool Right=0,Left=0,Crawl=0,Rotate=0;
};

#endif // EGG_H
