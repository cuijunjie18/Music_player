/********************************************************************************
** Form generated from reading UI file 'cjj.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CJJ_H
#define UI_CJJ_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pre_button;
    QPushButton *open_button;
    QPushButton *next_button;
    QPushButton *play_mode;
    QPushButton *play_list;
    QListWidget *music_list;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *current_time;
    QSlider *music_Slider;
    QLabel *total_time;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(740, 528);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 390, 561, 91));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pre_button = new QPushButton(layoutWidget);
        pre_button->setObjectName(QString::fromUtf8("pre_button"));

        horizontalLayout->addWidget(pre_button);

        open_button = new QPushButton(layoutWidget);
        open_button->setObjectName(QString::fromUtf8("open_button"));

        horizontalLayout->addWidget(open_button);

        next_button = new QPushButton(layoutWidget);
        next_button->setObjectName(QString::fromUtf8("next_button"));

        horizontalLayout->addWidget(next_button);

        play_mode = new QPushButton(layoutWidget);
        play_mode->setObjectName(QString::fromUtf8("play_mode"));

        horizontalLayout->addWidget(play_mode);

        play_list = new QPushButton(layoutWidget);
        play_list->setObjectName(QString::fromUtf8("play_list"));

        horizontalLayout->addWidget(play_list);

        music_list = new QListWidget(centralwidget);
        music_list->setObjectName(QString::fromUtf8("music_list"));
        music_list->setGeometry(QRect(570, 30, 161, 281));
        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(70, 350, 501, 19));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        current_time = new QLabel(layoutWidget1);
        current_time->setObjectName(QString::fromUtf8("current_time"));

        horizontalLayout_2->addWidget(current_time);

        music_Slider = new QSlider(layoutWidget1);
        music_Slider->setObjectName(QString::fromUtf8("music_Slider"));
        music_Slider->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(music_Slider);

        total_time = new QLabel(layoutWidget1);
        total_time->setObjectName(QString::fromUtf8("total_time"));

        horizontalLayout_2->addWidget(total_time);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pre_button->setText(QString());
        open_button->setText(QString());
        next_button->setText(QString());
        play_mode->setText(QString());
        play_list->setText(QString());
        current_time->setText(QCoreApplication::translate("MainWindow", "00: :29", nullptr));
        total_time->setText(QCoreApplication::translate("MainWindow", "    04::30", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CJJ_H
