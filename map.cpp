#include "map.h"
#include"mainwindow.h"
#include "ui_mainwindow.h"
Map::Map()
{

        //初始化加载地图对象
        m_map1.load(MAP_PATH2);
        m_map2.load(MAP_PATH2);
        m_terminal.load(MAP_PATH3);
        //设置地图其实x轴坐标
        m_map1_posX = GAME_WIDTH;
        m_map2_posX = 0;
        m_t_x=GAME_WIDTH;

        //设置地图滚动速度
        m_scroll_speed = MAP_SCROLL_SPEED;
    }

    void Map::endmusic(){
        QMediaPlayer *player = new QMediaPlayer();
        player->setMedia(QUrl("qrc:/res/end.wav"));
        player->setVolume(40);//音量
        player->play();
    }

    void Map::mapPosition()
    {
        //处理第一张图片滚动
        //    m_map1_posX -= MAP_SCROLL_SPEED;
        if(t>=20&&m_t_x>=0){
            m_t_x-=5*MAP_SCROLL_SPEED;
            endmusic();
        }

        if(m_map1_posX <= 0)
        {
            m_map1_posX =GAME_WIDTH;
        }

        //处理第二张图片滚动
        //    m_map2_posX -= MAP_SCROLL_SPEED;
        if(m_map2_posX <= -GAME_WIDTH )
        {
            m_map2_posX =0;
            t++;
        }


}
