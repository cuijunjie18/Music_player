#ifndef WINDOW_CJJ_H
#define WINDOW_CJJ_H

#include <QMainWindow>
#include <QString>
#include <QMediaPlayer>
#include "ui_cjj.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow{
    Q_OBJECT
public:
    /*类函数*/
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow();
    void init_button();
    void set_button_style(QPushButton *button,const QString &filename,
        int w = 50,int h = 50);
    void connect_button();
    void set_background(const QString &filename);
    void check_multimedia_service();
    void demo_use_QSoundEffect(const QString &music_path);

    /*类属性*/
    bool play_flag = false; // 默认不播放
private slots:
    void play_or_stop();
private:
    Ui::MainWindow* ui; // 指向ui的指针
    QMediaPlayer* music_player; // 音频播放器
};

#endif