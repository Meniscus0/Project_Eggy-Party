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

    //初始化矩形框，将蛋仔放置在地图中央底部。
    m_Rect.setWidth(changePic().width());
    m_Rect.setHeight(changePic().height());
    m_Rect.moveTo(e_X,e_Y);

    // 初始化跳跃定时器
    jump_Timer.setInterval(400);
    jump_Timer.setSingleShot(true);


}
//成员函数，根据蛋仔的状态返回对应的图片资源
QPixmap Egg::changePic(){
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
//成员函数，用于设置蛋仔的位置。
void Egg::setPosition(int x, int y)
{
    e_X = x;
    e_Y = y;
    m_Rect.moveTo(e_X,e_Y);
}

void Egg::jump()
{
    //只有在蛋仔在地面上时才能跳跃。
    if(e_Y==MAP_HEIGHT-m_Rect.height()){
        fall_speed=3;
        jump_Timer.start();
    }
}

//成员函数，表示蛋仔在Y轴方向上的更新。该函数根据蛋仔是否在跳跃状态来更新蛋仔的Y轴坐标，从而实现跳跃和下落。
void Egg::updateY(){
//如果蛋仔正在跳跃状态，那么就将它的Y坐标向上移动一个速度V_y的距离，从而实现跳跃的效果。
    if(jump_Timer.isActive()){
        e_Y-=V_y;
    }
//如果蛋仔不在跳跃状态，那么就让它以一个加速度GRAVITY的速度向下移动，从而实现下落的效果。
    else{
        fall_speed+=GRAVITY;
        e_Y+=fall_speed;
    }
//保证蛋仔不会穿过地图底部
    if(e_Y>=MAP_HEIGHT-m_Rect.height()){
        e_Y=MAP_HEIGHT-m_Rect.height();
    }

}
