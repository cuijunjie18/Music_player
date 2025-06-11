MainWindow::MainWindow(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("音乐播放器");

    // 设置按钮样式
    ui->pre_button->setFixedSize(50, 50);
    
    // 确保使用资源路径 (以 :/ 开头)
    ui->pre_button->setIcon(QIcon(":/resources/icons/pre_p.png"));
    ui->pre_button->setIconSize(QSize(50, 50)); 
    
    // 设置透明背景 - 使用更可靠的样式表
    ui->pre_button->setStyleSheet(
        "QPushButton {"
        "   background-color: transparent;"  // 透明背景
        "   border: none;"                   // 去除边框
        "}"
        "QPushButton:hover {"                // 鼠标悬停效果
        "   background-color: rgba(100, 100, 100, 50);"
        "}"
    );
    
    // 确保按钮接受鼠标事件
    ui->pre_button->setAttribute(Qt::WA_Hover, true);
}

 //    // 设置透明背景 - 使用更可靠的样式表
    //    ui->pre_button->setStyleSheet(
    //     "QPushButton {"
    //     "   background-color: transparent;"  // 透明背景
    //     "   border: none;"                   // 去除边框
    //     "}"
    //     "QPushButton:hover {"                // 鼠标悬停效果
    //     "   background-color: rgba(100, 100, 100, 50);"
    //     "}"
    // );
    // ui->pre_button->setStyleSheet("background-color: rgba(247, 193, 193, 0.3)");