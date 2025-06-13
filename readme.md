## 基于qt5的轻量化音频播放器

### 背景

c++开发练手项目

### 开发日志

- 2025-6.11 
  - 资源文件添加完成.
  - 完成按钮图标的初始化，按钮添加悬停与点击效果.
  - 完成背景的设置.
  - 完成音乐媒体器的环境配置，支持点击播放音乐，但是每次暂停后要从头开始播放.

- 2025-6.12
  - 添加上下切换的按钮的逻辑.
  - 实现不同播放模式的变化逻辑.
  - 添加music_list的UI的变化显示逻辑.
  - 关闭了音乐播放功能，用于调试.

- 2025-6.13
  - 修复音乐播放功能.
  - 添加音乐列表的渐进式动画.
  - 添加音乐播放进度条.

### 环境问题

- 安装qt5-multimedia库
  ```shell
  sudo apt-get install qtmultimedia5-dev
  ```

- 安装核心 GStreamer 插件和 Qt 多媒体支持
  ```shell
  sudo apt install gstreamer1.0-plugins-base \
                 gstreamer1.0-plugins-good \
                 gstreamer1.0-plugins-bad \
                 gstreamer1.0-plugins-ugly \
                 gstreamer1.0-libav \
                 libgstreamer-plugins-base1.0-dev \
                 qtmultimedia5-dev \
                 libqt5multimedia5-plugins
  ```
  测试是否可以播放
  ```shell
  gst-launch-1.0 playbin uri=file:///home/cjj/Music/起风了-动漫唯美风.ogg
  ```

### 其他

- .mp3转.wav
  ```shell
  ffmpeg -i <origin.mp3> <origin.wav>
  ```

- 信号绑定槽函数要确保所有的变量、函数都存在
  错误例子
  ```cpp
  connect(music_player,&QMediaPlayer::positionChanged,this,&MainWindow::HandleMusicPosition); // 处理音乐进度
  music_player = new QMediaPlayer(this)
  ```

  正确做法
  ```cpp
  music_player = new QMediaPlayer(this)
  connect(music_player,&QMediaPlayer::positionChanged,this,&MainWindow::HandleMusicPosition); // 处理音乐进度
  ```