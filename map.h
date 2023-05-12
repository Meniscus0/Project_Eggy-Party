#ifndef MAP_H
#define MAP_H
#include"config.h"

class Map
{
public:
    Map();
    //地图滚动坐标计算
    void mapPosition();
    void endmusic();
    //地图图片对象
    QPixmap m_map1;
    QPixmap m_map2;
    QPixmap m_terminal;
    //地图Y轴坐标
    int m_map1_posX= GAME_WIDTH;
    int m_map2_posX=0;
    int m_t_x=10*GAME_WIDTH;

    //地图滚动幅度
    int m_scroll_speed;
    int t=0;
};

#endif // MAP_H
