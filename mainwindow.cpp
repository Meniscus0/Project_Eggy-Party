#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QProcess>
void MainWindow::startMusic(){
    QMediaPlayer *player = new QMediaPlayer(this);
    player->setMedia(QUrl("qrc:/res/start.wav"));
    player->setVolume(50);//音量
    player->play();
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    startMusic();
    ui->setupUi(this);
    setWindowTitle(GAME_TITLE);
    setWindowIcon(QIcon( GAME_ICON));
    ui->menu->hide();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initScene()
{
    //初始化窗口大小
    setFixedSize(GAME_WIDTH,GAME_HEIGHT);

    //设置窗口标题
    setWindowTitle(GAME_TITLE);

    setWindowIcon(QIcon( GAME_ICON));

    //定时器设置
    m_Timer.setInterval(GAME_RATE);
    playGame();

    connect(&m_Timer,&QTimer::timeout,[=](){
        updatePosition();    //更新坐标
        update();          //刷新屏幕
    });


}

void MainWindow::Win(){
    m_Timer.stop();
    ui->menu->show();
}
void MainWindow::playGame()
{
    //启动定时器
    m_Timer.start();

    //监听定时器
    connect(&m_Timer,&QTimer::timeout,[=](){
        //更新游戏中元素的坐标
        updatePosition();
        //重新绘制图片
        update();
        m_hero.updateY();
        if(m_map.m_t_x<=0){
            Win();
        }

    });
}


void MainWindow::gameMusic(){
    QMediaPlayer *player = new QMediaPlayer(this);
    player->setMedia(QUrl("qrc:/res/game.wav"));
    player->setVolume(50);//音量
    player->play();
}


void MainWindow::updatePosition()
{
    //更新地图坐标
    m_map.mapPosition();
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    //绘制地图
    painter.drawPixmap(m_map.m_map1_posX,0 , m_map.m_map1);
    painter.drawPixmap(m_map.m_map2_posX,0, m_map.m_map2);
    painter.drawPixmap(m_map.m_t_x,0,m_map.m_terminal);
    painter.drawPixmap(m_hero.m_X,m_hero.m_Y,m_hero.getImg());

    //    补充绘制左侧地图
    //    for(int i=-GAME_WIDTH;i>=-10*GAME_WIDTH;i-=GAME_WIDTH)

}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    int x = event->x() - m_hero.m_Rect.width()*0.5; //鼠标位置 - 蛋仔矩形的一半
    int y = event->y() - m_hero.m_Rect.height()*0.5;

    //边界检测
    if(x <= 0 )
    {
        x = 0;
    }
    if(x >= GAME_WIDTH - m_hero.m_Rect.width())
    {
        x = GAME_WIDTH - m_hero.m_Rect.width();
    }
    if(y <= 0)
    {
        y = 0;
    }
    if(y >= GAME_HEIGHT - m_hero.m_Rect.height())
    {
        y = GAME_HEIGHT - m_hero.m_Rect.height();
    }
    m_hero.setPosition(x,y);
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    m_hero.Crawl=0,m_hero.Right=0,m_hero.Left=0,  m_hero.Rotate=0;
    bool jp=(event->key() == Qt::Key_W);
    if (jp) {  // 如果按下了W键
        m_hero.jump();
    }
    if (event->key() == Qt::Key_Space){  // 如果按下了空格键
        m_hero.Crawl=1;
        m_map.m_map2_posX=m_map.m_map2_posX-300;
        m_map.m_map1_posX=m_map.m_map1_posX-300;

        //       m_hero.m_X= m_hero.m_X+100;
    }
    if (event->key() == Qt::Key_D) {  // 如果按下了D键
        m_hero.Right=1;
        m_map.m_map2_posX=m_map.m_map2_posX-50;
        m_map.m_map1_posX=m_map.m_map1_posX-50;
        //       m_hero.m_X= m_hero.m_X+10;
    }
    if (event->key() == Qt::Key_A) {  // 如果按下了A键
        m_hero.Left=1;
        m_map.m_map2_posX=m_map.m_map2_posX+50;
        m_map.m_map1_posX=m_map.m_map1_posX+50;
        if(m_map.m_map2_posX>=0)
            m_map.m_map2_posX=0;
        if(m_map.m_map1_posX>=GAME_WIDTH)
            m_map.m_map1_posX=GAME_WIDTH;

        //       m_hero.m_X= m_hero.m_X-10;
    }

    if (event->key() == Qt::Key_S) {  // 如果按下了S键
        m_hero.Rotate=1;
        m_map.m_map2_posX=m_map.m_map2_posX-200;
        m_map.m_map1_posX=m_map.m_map1_posX-200;
        //       m_hero.m_X= m_hero.m_X-10;
    }


}



void MainWindow::on_playButton_clicked()
{
    ui->playButton->hide();
    ui->quitButton->hide();
    ui->frame->hide();
    initScene();
    gameMusic();
}

void MainWindow::on_quitButton_clicked()
{

    QApplication* app;
     app->quit();

}


void MainWindow::on_menu_clicked()
{
     qApp->quit();
     QProcess::startDetached(qApp->applicationFilePath(), QStringList());
}

