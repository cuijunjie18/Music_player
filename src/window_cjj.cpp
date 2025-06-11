#include "window_cjj.h"
#include "qt_common.h"

MainWindow::MainWindow(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    /* 设置UI界面 */
    ui->setupUi(this);

    /* 设置窗口标题 */
    setWindowTitle("音乐播放器");

    /* 固定窗口大小 */
    setFixedSize(this->size());

    /* 设置背景图片 */
    set_background(":/backgrounds/a.png");

    /* 初始化按钮 */
    init_button();
    connect_button();

    /* 检查多媒体服务是否可用 */
    check_multimedia_service();

    // 使用多媒体
    music_player = new QMediaPlayer(this);
    QString music_path = "/home/cjj/Music/起风了-动漫唯美风.ogg";
    music_player->setMedia(QUrl::fromLocalFile(music_path));
}

// 初始化按钮
void MainWindow::init_button(){
    set_button_style(ui->pre_button,":/icons/pre_p.png");
    set_button_style(ui->open_button, ":/icons/begin.png");  // 一开始为等待开启图标
    set_button_style(ui->next_button, ":/icons/next_p.png");
    set_button_style(ui->play_mode, ":/icons/sequence_play.png");
    set_button_style(ui->play_list, ":/icons/music_menu.png");
}

// 设置按钮样式
void MainWindow::set_button_style(QPushButton *button,const QString &filename,
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
void MainWindow::connect_button(){
    connect(ui->open_button,&QPushButton::clicked,this,&MainWindow::play_or_stop);
}

// 设置背景
void MainWindow::set_background(const QString &filename){
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
void MainWindow::check_multimedia_service(){
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
void MainWindow::demo_use_QSoundEffect(const QString &music_path){
    // 多媒体不可用，用声音
    QSoundEffect *effect = new QSoundEffect(this);
    effect->setSource(QUrl::fromLocalFile(music_path));
    effect->play();
}


/*槽函数集合*/
void MainWindow::play_or_stop(){
    play_flag ^= 1; // 状态取反
    if (play_flag){
        set_button_style(ui->open_button, ":/icons/stop.png");
        music_player->play();
    }
    else{
        set_button_style(ui->open_button, ":/icons/begin.png");
        music_player->stop();
    }
}

// 析构函数，释放类资源
MainWindow::~MainWindow(){
    delete ui;
}

