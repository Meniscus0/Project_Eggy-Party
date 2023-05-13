#include "map.h"
#include"mainwindow.h"
#include "ui_mainwindow.h"
Map::Map()
{

        //初始化加载地图对象
//    第一张图元素太多，比较杂乱，遂都采用第二张图
        map1.load(MAP_PATH2);
        map2.load(MAP_PATH2);
//        终点地图
        m_terminal.load(MAP_PATH3);
        //设置地图其实x轴坐标
        map1_X = MAP_WIDTH;
        map2_X = 0;
        m_t_x=MAP_WIDTH;
    }



    void Map::mapPosition()
    {

      //控制终点的远近
        if(t>=MAP_LENGTH&&m_t_x>0){
            m_t_x-=5*MAP_SCROLL_SPEED;
        }
         //处理第一张图片循环
        if(map1_X <= 0)
        {
            map1_X =MAP_WIDTH;
        }

        //处理第二张图片循环
        if(map2_X <= -MAP_WIDTH )
        {
            map2_X =0;
            t++;
        }
}
