#include "window_cjj.h"
#include <QIcon>
#include <QSize>
#include <QPixmap> // 图片类
#include <QPalette>
#include <QGraphicsOpacityEffect>

MainWindow::MainWindow(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    // 设置UI界面
    ui->setupUi(this);

    // 设置窗口标题
    setWindowTitle("音乐播放器");

    // 初始化按钮
    init_button();

    // 设置背景图片
    set_background(":/backgrounds/a.png");
}

void MainWindow::init_button(){
    set_button_style(ui->pre_button,":/icons/pre_p.png");
    set_button_style(ui->open_button, ":/icons/begin.png");  // 一开始为等待开启图标
    set_button_style(ui->next_button, ":/icons/next_p.png");
    set_button_style(ui->play_mode, ":/icons/sequence_play.png");
    set_button_style(ui->play_list, ":/icons/music_menu.png");
}

void MainWindow::set_button_style(QPushButton *button,const QString &filename,
        int w,int h){
    button->setFixedSize(w,h);
    button->setIcon(QIcon(filename));
    button->setIconSize(QSize(w,h));
    button->setStyleSheet(
        "background-color: transparent;"
        "border: none;"
    );
}

void MainWindow::set_background(const QString &filename){
    // 获取背景图片并进行放缩
    QPixmap pixmap(filename);
    QSize window_size = this->size();
    QPixmap scale_pixmap = pixmap.scaled(
        window_size,
        Qt::IgnoreAspectRatio,
        Qt::SmoothTransformation
    );
    
    // // 创建一个与原图大小相同的 QImage，并支持透明通道
    // QImage image = pixmap.toImage().convertToFormat(QImage::Format_ARGB32);

    // // 修改每个像素的 alpha 值
    // double opacity = 1;
    // for (int y = 0; y < image.height(); ++y) {
    //     for (int x = 0; x < image.width(); ++x) {
    //         QRgb pixel = image.pixel(x, y);
    //         int alpha = static_cast<int>(qAlpha(pixel) * opacity);
    //         image.setPixelColor(x, y, QColor(qRed(pixel), qGreen(pixel), qBlue(pixel), alpha));
    //     }
    // }
                        
    // QPixmap scale_pixmap = QPixmap::fromImage(image).scaled(
    //     window_size,
    //     Qt::IgnoreAspectRatio,
    //     Qt::SmoothTransformation
    // );

    // 使用调色板
    QPalette palette = this->palette();
    palette.setBrush(QPalette::Window,QBrush(scale_pixmap));
    this->setPalette(palette); // 应用到窗口
}

MainWindow::~MainWindow(){
    delete ui;
}

