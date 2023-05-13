#ifndef MAP_H
#define MAP_H
#include"config.h"

class Map
{
public:
    Map();
    //地图滚动坐标计算
    void mapPosition();
    //地图图片对象
    QPixmap map1;
    QPixmap map2;
    QPixmap m_terminal;
    //地图X轴坐标
    int map1_X= MAP_WIDTH;
    int map2_X=0;
    int m_t_x=10*MAP_WIDTH;

//    记录地图循环的次数
    int t=0;
};

#endif // MAP_H
