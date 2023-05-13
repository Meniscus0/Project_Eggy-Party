#include "egg.h"

Egg::Egg()
{
    //初始化加载蛋仔图片资源
    right.load(EGG_RIGHT);
    left.load(EGG_LEFT);
    crawl.load(EGG_CRAWL);
    rotate.load(EGG_ROTATE);

    //初始化坐标
    e_X = MAP_WIDTH * 0.5 - changePic().width()*0.5;
    e_Y = MAP_HEIGHT - changePic().height();

    //初始化矩形框
    m_Rect.setWidth(changePic().width());
    m_Rect.setHeight(changePic().height());
    m_Rect.moveTo(e_X,e_Y);

    // 初始化跳跃定时器
    jump_Timer.setInterval(400);
    jump_Timer.setSingleShot(true);
    fall_speed=3;

}

QPixmap Egg::changePic(){              //根据位置获取角色状态图片
    if(Right==1){
        return right;
    }
    else if(Left==1){
        return left;
    }
    else if(Crawl==1){
        return crawl;
    }
    else if(Rotate==1){
        return rotate;
    }
    else{
        return right;
    }

}

void Egg::setPosition(int x, int y)
{
    e_X = x;
    e_Y = y;
    m_Rect.moveTo(e_X,e_Y);
}

//注
void Egg::jump()
{
//    在地面上才能跳跃
    if(e_Y==MAP_HEIGHT-m_Rect.height()){
        fall_speed=3;
        jump_Timer.start();
    }
}

void Egg::updateY(){

    if(jump_Timer.isActive()){
        e_Y-=V_y;
    }
    else{
        fall_speed+=GRAVITY;
        e_Y+=fall_speed;
    }

    if(e_Y>=MAP_HEIGHT-m_Rect.height()){
        e_Y=MAP_HEIGHT-m_Rect.height();
    }
}
