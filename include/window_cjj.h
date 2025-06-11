#ifndef WINDOW_CJJ_H
#define WINDOW_CJJ_H

#include <QMainWindow>
#include <QString>
#include "ui_cjj.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow{
    Q_OBJECT
public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow();
    void init_button();
    void set_button_style(QPushButton *button,const QString &filename,
        int w = 50,int h = 50);
    void set_background(const QString &filename);
private slots:
    
private:
    Ui::MainWindow* ui; // 指向ui的指针
};

#endif