#include "egg.h"

Egg::Egg()
{
    //初始化加载蛋仔图片资源
    m_Plane.load(HERO_RIGHT);
    right.load(HERO_RIGHT);
    left.load(HERO_LEFT);
    crawl.load(HERO_CRAWL);
    rotate.load(HERO_ROTATE);

    //初始化坐标
    m_X = GAME_WIDTH * 0.5 - getImg().width()*0.5;
    m_Y = GAME_HEIGHT - getImg().height();

    //初始化矩形框
    m_Rect.setWidth(getImg().width());
    m_Rect.setHeight(getImg().height());
    m_Rect.moveTo(m_X,m_Y);

    // 初始化跳跃定时器
    jump_Timer.setInterval(380);
    jump_Timer.setSingleShot(true);

    fall_speed=3;

}

QPixmap Egg::getImg(){              //根据位置获取角色状态图片
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
    m_X = x;
    m_Y = y;
    m_Rect.moveTo(m_X,m_Y);
}


void Egg::jump()
{
    if(m_Y==GAME_HEIGHT-m_Rect.height()){
        fall_speed=3;
    }
    if(jump_Timer.remainingTime()>200&&jump_Timer.isActive()){
        return;
    }
    if(m_Y==GAME_HEIGHT-m_Rect.height()){
        jump_Timer.start();
    }


}

void Egg::updateY(){
    if(jump_Timer.isActive()){
        m_Y-=jump_Timer.remainingTime()/20;
    }
    else{
        fall_speed+=0.04;
        m_Y+=fall_speed;
    }

    if(m_Y>=GAME_HEIGHT-m_Rect.height()){
        m_Y=GAME_HEIGHT-m_Rect.height();
    }

    //    m_Rect.moveTo(m_X,m_Y+8);
}

