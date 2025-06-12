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
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
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
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(740, 528);
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
        music_list->setGeometry(QRect(575, 30, 161, 281));
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
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CJJ_H
