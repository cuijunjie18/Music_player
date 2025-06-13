#ifndef WINDOW_CJJ_H
#define WINDOW_CJJ_H

#include "qt_common.h"
#include "ui_cjj.h"

enum PlayMode{
    Sequence_mode = 0,
    Random_mode = 1,
    Loop_mode = 2
};

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow{
    Q_OBJECT
public:
    /*类函数*/
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow();
    void InitButton();
    void SetButtonStyle(QPushButton *button,const QString &filename,
        int w = 50,int h = 50);
    void ConnectButton();
    void SetBackground(const QString &filename);
    void CheckMultimediaService();
    void DemoQSoundEffect(const QString &music_path);
    void DemoQMediaMusic(const QString &music_path);
    void BuildMusicList(const QString &music_dir);
    void BeautifyMusicList();
    void UpdateMusic();
    void ShowMusicList(QWidget* window); // 动画显示音乐列表
    void HideMusicList(QWidget* window); // 动画隐藏音乐列表

    /*类属性*/
    bool m_hide_flag;
private slots:
    void HandleOpenButton();
    void HandlePlayMode();
    void HandlePreButton();
    void HandleNextButton();
    void HandlePlayList();
private:
    Ui::MainWindow* ui; // 指向ui的指针
    QMediaPlayer* music_player; // 音频播放器
    QFileInfoList music_list; // 音乐列表
    int music_index; // 现在播放的音乐下标
    int music_nums; // 音乐数量
    PlayMode play_mode; // 播放模式
};

#endif