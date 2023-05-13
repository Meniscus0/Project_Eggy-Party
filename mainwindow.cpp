#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QProcess>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    startMusic();
    ui->setupUi(this);
    ui->restartButton->hide();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initScene()
{
    //初始化窗口大小
    setFixedSize(MAP_WIDTH,MAP_HEIGHT);

    //设置窗口标题
    setWindowTitle(GAME_TITLE);
    //设置窗口图标
    setWindowIcon(QIcon( GAME_ICON));

    //定时器设置，设置计时器间隔时间
    e_Timer.setInterval(GAME_RATE);

    playGame();

}

void MainWindow::Win(){
    e_Timer.stop(); //停止计时器
    ui->restartButton->show();
}

void MainWindow::playGame()
{
    //启动定时器
    e_Timer.start();

    //监听定时器
//    [=]表示以值传递的方式捕获所有外部变量，即lambda表达式可以访问其所在作用域中的所有变量。

    connect(&e_Timer,&QTimer::timeout,[=](){
        //更新地图
        updateMap();
        //重新绘制图片
        update();
       //更新蛋仔的纵坐标
        eggBoy.updateY();

//        终点地图移动到左边界
        if(map.m_t_x<=0){
            Win();
            endmusic();
        }

    });
}


 //播放开始音乐
void MainWindow::startMusic(){
    QMediaPlayer *player = new QMediaPlayer(this);
    player->setMedia(QUrl("qrc:/res/start.wav"));
    player->setVolume(50);//音量
    player->play();
}

//播放游戏音乐
void MainWindow::gameMusic(){
    QMediaPlayer *player = new QMediaPlayer(this);
    player->setMedia(QUrl("qrc:/res/game.wav"));
    player->setVolume(50);//音量
    player->play();
}
//播放胜利音乐
void MainWindow::endmusic(){
    QMediaPlayer *player = new QMediaPlayer();
    player->setMedia(QUrl("qrc:/res/end.wav"));
    player->setVolume(50);//音量
    player->play();
}

void MainWindow::updateMap()
{
    //更新地图坐标
    map.mapPosition();
}


void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    //绘制三张地图
    painter.drawPixmap(map.map1_X,0 , map.map1);
    painter.drawPixmap(map.map2_X,0, map.map2);
    //仅仅画出，没有显示到窗口中
    painter.drawPixmap(map.m_t_x,0,map.m_terminal);
    //画蛋仔
    painter.drawPixmap(eggBoy.e_X,eggBoy.e_Y,eggBoy.changePic());

}


//鼠标控制
void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    //鼠标位置 - 蛋仔矩形的一半
    int x = event->x() - eggBoy.m_Rect.width()*0.5;
    int y = event->y() - eggBoy.m_Rect.height()*0.5;

    //边界检测
    if(x <= 0 )
    {
        x = 0;
    }
    if(x >= MAP_WIDTH - eggBoy.m_Rect.width())
    {
        x = MAP_WIDTH - eggBoy.m_Rect.width();
    }
    if(y <= 0)
    {
        y = 0;
    }
    if(y >= MAP_HEIGHT - eggBoy.m_Rect.height())
    {
        y = MAP_HEIGHT - eggBoy.m_Rect.height();
    }

    eggBoy.setPosition(x,y);
}

//键盘控制
void MainWindow::keyPressEvent(QKeyEvent *event)
{
    eggBoy.Crawl=0,eggBoy.Right=0,eggBoy.Left=0,  eggBoy.Rotate=0;

    // 按下W键跳跃
    bool jp=(event->key() == Qt::Key_W);
    if (jp) {
        eggBoy.jump();
    }
     // 按下空格键翻滚
    if (event->key() == Qt::Key_Space){
        eggBoy.Crawl=1;
        map.map2_X=map.map2_X-300;
        map.map1_X=map.map1_X-300;
    }
    // 按下D键右移
    if (event->key() == Qt::Key_D) {
        eggBoy.Right=1;
        map.map2_X=map.map2_X-50;
        map.map1_X=map.map1_X-50;
    }

    if (event->key() == Qt::Key_A) {
        eggBoy.Left=1;
        map.map2_X=map.map2_X+50;
        map.map1_X=map.map1_X+50;

        //防止蛋仔过度向左移动
        if(map.map2_X>=0)
            map.map2_X=0;
        if(map.map1_X>=MAP_WIDTH)
            map.map1_X=MAP_WIDTH;
    }

    // 按下S键飞扑
    if (event->key() == Qt::Key_S) {
        eggBoy.Rotate=1;
        map.map2_X=map.map2_X-200;
        map.map1_X=map.map1_X-200;
    }

}


//开始键
void MainWindow::on_playButton_clicked()
{
    ui->playButton->hide();
    ui->quitButton->hide();
    ui->frame->hide();
    initScene();
    gameMusic();
}
//退出键
void MainWindow::on_quitButton_clicked()
{

    QApplication* app = nullptr;
    app->quit();

}

//重玩键
void MainWindow::on_restartButton_clicked()
{
     qApp->quit();
     QProcess::startDetached(qApp->applicationFilePath(), QStringList());
}

