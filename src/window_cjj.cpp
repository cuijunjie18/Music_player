#include "window_cjj.h"
#include "qt_common.h"
#include <stdlib.h>

MainWindow::MainWindow(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    play_mode(Sequence_mode) // 初始化为顺序播放
{
    /* 设计随机数种子 */
    srand((time(NULL)));

    /* 设置UI界面 */
    ui->setupUi(this);

    /* 设置窗口标题 */
    setWindowTitle("音乐播放器");

    /* 固定窗口大小 */
    setFixedSize(this->size());

    /* 设置背景图片 */
    SetBackground(":/backgrounds/a.png");

    /* 初始化按钮 */
    InitButton();
    ConnectButton();

    /* 检查多媒体服务是否可用 */
    CheckMultimediaService();

    // 使用多媒体
    music_player = new QMediaPlayer(this);

    // 构建歌曲列表
    QString music_dir = "/home/cjj/Music";
    BuildMusicList(music_dir);
}

// 初始化按钮
void MainWindow::InitButton(){
    SetButtonStyle(ui->pre_button,":/icons/pre_p.png");
    SetButtonStyle(ui->open_button, ":/icons/begin.png");  // 一开始为等待开启图标
    SetButtonStyle(ui->next_button, ":/icons/next_p.png");
    SetButtonStyle(ui->play_mode, ":/icons/sequence_play.png");
    SetButtonStyle(ui->play_list, ":/icons/music_list.png");
}

// 设置按钮样式
void MainWindow::SetButtonStyle(QPushButton *button,const QString &filename,
        int w,int h){
    if (!QFile::exists(filename)){
        qCritical() << filename << "is not found!" << "\n"; 
        // qFatal("%s is not found",&filename.toStdString()[0]);
    }
    button->setFixedSize(w,h);
    button->setIcon(QIcon(filename));
    button->setIconSize(QSize(w,h));
    // button->setStyleSheet(
    //     "background-color: transparent;"
    //     "border: none;"
    // );
    button->setStyleSheet(
        "QPushButton {"
            "background-color: transparent;"      // 默认透明
            // "color: white;"                   // 字体颜色
            "border: none;"                   // 无边框
            // "padding: 10px 20px;"             // 内边距
            // "font-size: 16px;"
        "}"
        "QPushButton:hover {"
            "background-color: rgba(100, 100, 100, 0.5);"      // 悬停时颜色变深
        "}"
        "QPushButton:pressed {"
            "background-color: rgba(100, 100, 100, 0.3);"      // 点击时颜色更深
        "}"
    );
    
}

// 按钮绑定槽函数
void MainWindow::ConnectButton(){
    connect(ui->open_button,&QPushButton::clicked,this,&MainWindow::HandleOpenButton);
    connect(ui->play_mode,&QPushButton::clicked,this,&MainWindow::HandlePlayMode);
    connect(ui->pre_button,&QPushButton::clicked,this,&MainWindow::HandlePreButton);
    connect(ui->next_button,&QPushButton::clicked,this,&MainWindow::HandleNextButton);
    connect(ui->play_list,&QPushButton::clicked,this,&MainWindow::HandlePlayList);
}

// 设置背景
void MainWindow::SetBackground(const QString &filename){
    if (!QFile::exists(filename)){
        qCritical() << filename << "is not found!" << "\n"; 
        // qFatal("%s is not found",&filename.toStdString()[0]);
    }

    // 获取背景图片并进行放缩
    QPixmap pixmap(filename);
    QSize window_size = this->size();
    QPixmap scale_pixmap = pixmap.scaled(
        window_size,
        Qt::IgnoreAspectRatio,
        Qt::SmoothTransformation
    );

    // 使用调色板
    QPalette palette = this->palette();
    palette.setBrush(QPalette::Window,QBrush(scale_pixmap));
    this->setPalette(palette); // 应用到窗口
}

// 检测multimedia_service
void MainWindow::CheckMultimediaService(){
    QMediaPlayer demo;
    if (!demo.isAvailable()) {
        QMessageBox::critical(this, "多媒体服务错误",
            "无法加载多媒体服务：\n"
            "1. 请确保已安装 gstreamer 插件\n"
            "2. 检查 Qt 多媒体模块是否正确安装");
        return;
    }
}

// 使用QSoundEffect播放音乐： 仅支持.wav格式
void MainWindow::DemoQSoundEffect(const QString &music_path){
    // 多媒体不可用，用声音
    QSoundEffect *effect = new QSoundEffect(this);
    effect->setSource(QUrl::fromLocalFile(music_path));
    effect->play();
}

// 使用QMediaPlayer播放音乐
void MainWindow::DemoQMediaMusic(const QString &music_path){
    music_player->setMedia(QUrl::fromLocalFile(music_path));
    if (music_player->state() == QMediaPlayer::StoppedState) qDebug() << "Music is stopped" << "\n";
    music_player->play();
}

// 获取音乐列表
void MainWindow::BuildMusicList(const QString &music_dir){
    QDir dir(music_dir);
    if (!dir.exists()){
        QMessageBox::warning(this,"音乐列表",\
            "文件夹不存在!\n"
            "请重新确认文件夹路径!\n");
    }
    music_list = dir.entryInfoList(QDir::Files);

    if (music_list.size() == 0){
        QMessageBox::warning(this,"音乐列表",
            "音乐列表为空!\n"
            "请重新确认文件夹路径!\n");
    }

    music_nums = music_list.size();
    music_index = 0; // 默认第一首歌

    for (auto music : music_list){
        // ui->music_list->addItem(music.fileName());
        ui->music_list->addItem(music.baseName());
    }
    ui->music_list->setCurrentRow(0); // 初始化显示第1首歌
}

/*槽函数集合*/
void MainWindow::HandleOpenButton(){
    QMediaPlayer::State state = music_player->state();
    if (state == QMediaPlayer::PausedState){
        SetButtonStyle(ui->open_button, ":/icons/stop.png");
        music_player->play();
    }
    else if (state == QMediaPlayer::PlayingState){
        SetButtonStyle(ui->open_button, ":/icons/begin.png");
        music_player->pause(); // 用pause而不是stop
    }
    else if (state == QMediaPlayer::StoppedState){
        SetButtonStyle(ui->open_button,":/icons/stop.png");
        music_player->play();
        // qDebug() << "Music is start!" << "\n";
    }
}
void MainWindow::HandlePlayMode(){
    int temp = (play_mode + 1) % 3;
    play_mode = static_cast<PlayMode>(temp);
    // qDebug() << play_mode << "\n";
    switch (play_mode) {
    case Sequence_mode:
        SetButtonStyle(ui->play_mode, ":/icons/sequence_play.png");
        break;
    case Random_mode:
        SetButtonStyle(ui->play_mode, ":/icons/random_play.png");
        break;
    case Loop_mode:
        SetButtonStyle(ui->play_mode, ":/icons/loop_play.png");
        break;
    default:break;
    }
}
void MainWindow::HandlePreButton(){
    switch (play_mode) {
    case Sequence_mode:
        music_index = (music_index - 1 + music_nums) % music_nums;
        // music_player->setMedia(QUrl::fromLocalFile(music_list[music_index].fileName()));
        // music_player->play();
        break;
    case Random_mode:{
        int pre_save = music_index;
        do{
            music_index = rand() % music_nums;
        } while (pre_save == music_index);
        break;
    }
    case Loop_mode:
        break;
    default:
        qWarning() << "Play mode is not exist!" << "\n";
        break;
    }
    UpdateMusic();
    qDebug() << music_index << " " << music_list[music_index].fileName() << "\n";
}
void MainWindow::HandleNextButton(){
    switch (play_mode) {
    case Sequence_mode:
        music_index = (music_index + 1) % music_nums;
        // music_player->setMedia(QUrl::fromLocalFile(music_list[music_index].fileName()));
        // music_player->play();
        break;
    case Random_mode:{
        int pre_save = music_index;
        do{
            music_index = rand() % music_nums;
        } while (pre_save == music_index);
        break;
    }
    case Loop_mode:
        break;
    default:
        qWarning() << "Play mode is not exist!" << "\n";
        break;
    }
    qDebug() << music_index << " " << music_list[music_index].fileName() << "\n";
    UpdateMusic();
}
void MainWindow::HandlePlayList(){
    
}

// 用music_index更新音乐UI和播放
void MainWindow::UpdateMusic(){
    ui->music_list->setCurrentRow(music_index);
}

// 析构函数，释放类资源
MainWindow::~MainWindow(){
    delete ui;
}

