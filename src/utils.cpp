#include "utils.h"

/* 毫秒->秒 */
qint64 MillsencondsToSeconds(qint64 millseconds){
    return millseconds / 1000;
}

/* 秒格式化： 仅支持1hour内的 */
QString Seconds2DurationFormat(qint64 seconds){
    qint64 minute_int = seconds / 60;
    qint64 seconds_int = seconds % 60;
    std::string minute_str = std::to_string(minute_int);
    std::string seconds_str = std::to_string(seconds_int);
    if (seconds_int < 10) seconds_str = "0" + seconds_str; // 补充前导零
    std::string results = minute_str + ":" + seconds_str;
    return QString(&results[0]);
}

/* 检查QMediaPlayer媒体Service是否正常 */
void CheckMultimediaService(QWidget *parent){
    QMediaPlayer demo;
    if (!demo.isAvailable()) {
        QMessageBox::critical(parent, "多媒体服务错误",
            "无法加载多媒体服务：\n"
            "1. 请确保已安装 gstreamer 插件\n"
            "2. 检查 Qt 多媒体模块是否正确安装");
        return;
    }
}

/* 使用QSoundEffect播放音乐Demo： 仅支持.wav格式 */
void DemoQSoundEffect(const QString &music_path){
    // 多媒体不可用，用声音
    QSoundEffect *effect = new QSoundEffect;
    effect->setSource(QUrl::fromLocalFile(music_path));
    effect->play();
}

/* QMediaPlayer播放音乐Demo */
void DemoQMediaMusic(const QString &music_path){
    QMediaPlayer* music_player;
    music_player = new QMediaPlayer;
    music_player->setMedia(QUrl::fromLocalFile(music_path));
    if (music_player->state() == QMediaPlayer::StoppedState) qDebug() << "Music is stopped" << "\n";
    music_player->play();
}