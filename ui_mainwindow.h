/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Thu Dec 27 18:28:20 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDockWidget>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QScrollArea>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>
#include "renderer.hpp"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_3;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout_4;
    Renderer *widget;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QDockWidget *dockWidget_2;
    QWidget *dockWidgetContents_2;
    QGridLayout *gridLayout_2;
    QListWidget *listWidget_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        MainWindow->setIconSize(QSize(50, 50));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout_3 = new QGridLayout(centralWidget);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        scrollArea = new QScrollArea(centralWidget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setStyleSheet(QString::fromUtf8(""));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 524305, 530));
        gridLayout_4 = new QGridLayout(scrollAreaWidgetContents);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        widget = new Renderer(scrollAreaWidgetContents);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMinimumSize(QSize(900000, 0));
        widget->setMaximumSize(QSize(900000, 760));

        gridLayout_4->addWidget(widget, 0, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout_3->addWidget(scrollArea, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        mainToolBar->setIconSize(QSize(30, 30));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        dockWidget_2 = new QDockWidget(MainWindow);
        dockWidget_2->setObjectName(QString::fromUtf8("dockWidget_2"));
        dockWidget_2->setFeatures(QDockWidget::DockWidgetFloatable|QDockWidget::DockWidgetMovable);
        dockWidgetContents_2 = new QWidget();
        dockWidgetContents_2->setObjectName(QString::fromUtf8("dockWidgetContents_2"));
        gridLayout_2 = new QGridLayout(dockWidgetContents_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        listWidget_2 = new QListWidget(dockWidgetContents_2);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/img/m1.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem = new QListWidgetItem(listWidget_2);
        __qlistwidgetitem->setIcon(icon1);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/img/m2.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem1 = new QListWidgetItem(listWidget_2);
        __qlistwidgetitem1->setIcon(icon2);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/img/m3.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem2 = new QListWidgetItem(listWidget_2);
        __qlistwidgetitem2->setIcon(icon3);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/img/m4.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem3 = new QListWidgetItem(listWidget_2);
        __qlistwidgetitem3->setIcon(icon4);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/img/m5.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem4 = new QListWidgetItem(listWidget_2);
        __qlistwidgetitem4->setIcon(icon5);
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/img/m6.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem5 = new QListWidgetItem(listWidget_2);
        __qlistwidgetitem5->setIcon(icon6);
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/img/m7.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem6 = new QListWidgetItem(listWidget_2);
        __qlistwidgetitem6->setIcon(icon7);
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/img/m8.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem7 = new QListWidgetItem(listWidget_2);
        __qlistwidgetitem7->setIcon(icon8);
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/img/m9.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem8 = new QListWidgetItem(listWidget_2);
        __qlistwidgetitem8->setIcon(icon9);
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/img/m10.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem9 = new QListWidgetItem(listWidget_2);
        __qlistwidgetitem9->setIcon(icon10);
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/img/m11.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem10 = new QListWidgetItem(listWidget_2);
        __qlistwidgetitem10->setIcon(icon11);
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/img/m12.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem11 = new QListWidgetItem(listWidget_2);
        __qlistwidgetitem11->setIcon(icon12);
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/img/m13.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem12 = new QListWidgetItem(listWidget_2);
        __qlistwidgetitem12->setIcon(icon13);
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/img/m14.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem13 = new QListWidgetItem(listWidget_2);
        __qlistwidgetitem13->setIcon(icon14);
        QIcon icon15;
        icon15.addFile(QString::fromUtf8(":/img/m15.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem14 = new QListWidgetItem(listWidget_2);
        __qlistwidgetitem14->setIcon(icon15);
        QIcon icon16;
        icon16.addFile(QString::fromUtf8(":/img/m16.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem15 = new QListWidgetItem(listWidget_2);
        __qlistwidgetitem15->setIcon(icon16);
        QIcon icon17;
        icon17.addFile(QString::fromUtf8(":/img/m17.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem16 = new QListWidgetItem(listWidget_2);
        __qlistwidgetitem16->setIcon(icon17);
        QIcon icon18;
        icon18.addFile(QString::fromUtf8(":/img/m18.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem17 = new QListWidgetItem(listWidget_2);
        __qlistwidgetitem17->setIcon(icon18);
        QIcon icon19;
        icon19.addFile(QString::fromUtf8(":/img/m19.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem18 = new QListWidgetItem(listWidget_2);
        __qlistwidgetitem18->setIcon(icon19);
        QIcon icon20;
        icon20.addFile(QString::fromUtf8(":/img/m20.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem19 = new QListWidgetItem(listWidget_2);
        __qlistwidgetitem19->setIcon(icon20);
        QIcon icon21;
        icon21.addFile(QString::fromUtf8(":/img/m21.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem20 = new QListWidgetItem(listWidget_2);
        __qlistwidgetitem20->setIcon(icon21);
        QIcon icon22;
        icon22.addFile(QString::fromUtf8(":/img/g.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem21 = new QListWidgetItem(listWidget_2);
        __qlistwidgetitem21->setIcon(icon22);
        QIcon icon23;
        icon23.addFile(QString::fromUtf8(":/img/g1.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem22 = new QListWidgetItem(listWidget_2);
        __qlistwidgetitem22->setIcon(icon23);
        QIcon icon24;
        icon24.addFile(QString::fromUtf8(":/img/g2.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem23 = new QListWidgetItem(listWidget_2);
        __qlistwidgetitem23->setIcon(icon24);
        QIcon icon25;
        icon25.addFile(QString::fromUtf8(":/img/g3.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem24 = new QListWidgetItem(listWidget_2);
        __qlistwidgetitem24->setIcon(icon25);
        QIcon icon26;
        icon26.addFile(QString::fromUtf8(":/img/g4.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem25 = new QListWidgetItem(listWidget_2);
        __qlistwidgetitem25->setIcon(icon26);
        QIcon icon27;
        icon27.addFile(QString::fromUtf8(":/img/g5.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem26 = new QListWidgetItem(listWidget_2);
        __qlistwidgetitem26->setIcon(icon27);
        QIcon icon28;
        icon28.addFile(QString::fromUtf8(":/img/g6.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem27 = new QListWidgetItem(listWidget_2);
        __qlistwidgetitem27->setIcon(icon28);
        QIcon icon29;
        icon29.addFile(QString::fromUtf8(":/img/g7.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem28 = new QListWidgetItem(listWidget_2);
        __qlistwidgetitem28->setIcon(icon29);
        QIcon icon30;
        icon30.addFile(QString::fromUtf8(":/img/g8.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem29 = new QListWidgetItem(listWidget_2);
        __qlistwidgetitem29->setIcon(icon30);
        QIcon icon31;
        icon31.addFile(QString::fromUtf8(":/img/g9.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem30 = new QListWidgetItem(listWidget_2);
        __qlistwidgetitem30->setIcon(icon31);
        QIcon icon32;
        icon32.addFile(QString::fromUtf8(":/img/g10.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem31 = new QListWidgetItem(listWidget_2);
        __qlistwidgetitem31->setIcon(icon32);
        QIcon icon33;
        icon33.addFile(QString::fromUtf8(":/img/g11.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem32 = new QListWidgetItem(listWidget_2);
        __qlistwidgetitem32->setIcon(icon33);
        QIcon icon34;
        icon34.addFile(QString::fromUtf8(":/img/g12.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem33 = new QListWidgetItem(listWidget_2);
        __qlistwidgetitem33->setIcon(icon34);
        QIcon icon35;
        icon35.addFile(QString::fromUtf8(":/img/g13.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem34 = new QListWidgetItem(listWidget_2);
        __qlistwidgetitem34->setIcon(icon35);
        QIcon icon36;
        icon36.addFile(QString::fromUtf8(":/img/g14.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem35 = new QListWidgetItem(listWidget_2);
        __qlistwidgetitem35->setIcon(icon36);
        QIcon icon37;
        icon37.addFile(QString::fromUtf8(":/img/g15.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem36 = new QListWidgetItem(listWidget_2);
        __qlistwidgetitem36->setIcon(icon37);
        QIcon icon38;
        icon38.addFile(QString::fromUtf8(":/img/s1.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem37 = new QListWidgetItem(listWidget_2);
        __qlistwidgetitem37->setIcon(icon38);
        QIcon icon39;
        icon39.addFile(QString::fromUtf8(":/img/s2.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem38 = new QListWidgetItem(listWidget_2);
        __qlistwidgetitem38->setIcon(icon39);
        QIcon icon40;
        icon40.addFile(QString::fromUtf8(":/img/platform1.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem39 = new QListWidgetItem(listWidget_2);
        __qlistwidgetitem39->setIcon(icon40);
        QIcon icon41;
        icon41.addFile(QString::fromUtf8(":/img/skull.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem40 = new QListWidgetItem(listWidget_2);
        __qlistwidgetitem40->setIcon(icon41);
        QIcon icon42;
        icon42.addFile(QString::fromUtf8(":/img/injection.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem41 = new QListWidgetItem(listWidget_2);
        __qlistwidgetitem41->setIcon(icon42);
        listWidget_2->setObjectName(QString::fromUtf8("listWidget_2"));
        listWidget_2->setIconSize(QSize(60, 60));
        listWidget_2->setViewMode(QListView::IconMode);

        gridLayout_2->addWidget(listWidget_2, 0, 0, 1, 1);

        dockWidget_2->setWidget(dockWidgetContents_2);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(2), dockWidget_2);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Astro Rush- level creator v0.0", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        dockWidget_2->setWhatsThis(QApplication::translate("MainWindow", "Wybierz rodzaj terenu", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        dockWidget_2->setWindowTitle(QApplication::translate("MainWindow", "Ceg\305\202y", 0, QApplication::UnicodeUTF8));

        const bool __sortingEnabled = listWidget_2->isSortingEnabled();
        listWidget_2->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidget_2->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem1 = listWidget_2->item(1);
        ___qlistwidgetitem1->setText(QApplication::translate("MainWindow", "1", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem2 = listWidget_2->item(2);
        ___qlistwidgetitem2->setText(QApplication::translate("MainWindow", "2", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem3 = listWidget_2->item(3);
        ___qlistwidgetitem3->setText(QApplication::translate("MainWindow", "3", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem4 = listWidget_2->item(4);
        ___qlistwidgetitem4->setText(QApplication::translate("MainWindow", "4", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem5 = listWidget_2->item(5);
        ___qlistwidgetitem5->setText(QApplication::translate("MainWindow", "5", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem6 = listWidget_2->item(6);
        ___qlistwidgetitem6->setText(QApplication::translate("MainWindow", "6", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem7 = listWidget_2->item(7);
        ___qlistwidgetitem7->setText(QApplication::translate("MainWindow", "7", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem8 = listWidget_2->item(8);
        ___qlistwidgetitem8->setText(QApplication::translate("MainWindow", "8", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem9 = listWidget_2->item(9);
        ___qlistwidgetitem9->setText(QApplication::translate("MainWindow", "9", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem10 = listWidget_2->item(10);
        ___qlistwidgetitem10->setText(QApplication::translate("MainWindow", "10", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem11 = listWidget_2->item(11);
        ___qlistwidgetitem11->setText(QApplication::translate("MainWindow", "11", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem12 = listWidget_2->item(12);
        ___qlistwidgetitem12->setText(QApplication::translate("MainWindow", "12", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem13 = listWidget_2->item(13);
        ___qlistwidgetitem13->setText(QApplication::translate("MainWindow", "13", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem14 = listWidget_2->item(14);
        ___qlistwidgetitem14->setText(QApplication::translate("MainWindow", "14", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem15 = listWidget_2->item(15);
        ___qlistwidgetitem15->setText(QApplication::translate("MainWindow", "15", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem16 = listWidget_2->item(16);
        ___qlistwidgetitem16->setText(QApplication::translate("MainWindow", "16", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem17 = listWidget_2->item(17);
        ___qlistwidgetitem17->setText(QApplication::translate("MainWindow", "17", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem18 = listWidget_2->item(18);
        ___qlistwidgetitem18->setText(QApplication::translate("MainWindow", "18", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem19 = listWidget_2->item(19);
        ___qlistwidgetitem19->setText(QApplication::translate("MainWindow", "19", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem20 = listWidget_2->item(20);
        ___qlistwidgetitem20->setText(QApplication::translate("MainWindow", "20", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem21 = listWidget_2->item(21);
        ___qlistwidgetitem21->setText(QApplication::translate("MainWindow", "21", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem22 = listWidget_2->item(22);
        ___qlistwidgetitem22->setText(QApplication::translate("MainWindow", "22", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem23 = listWidget_2->item(23);
        ___qlistwidgetitem23->setText(QApplication::translate("MainWindow", "23", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem24 = listWidget_2->item(24);
        ___qlistwidgetitem24->setText(QApplication::translate("MainWindow", "24", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem25 = listWidget_2->item(25);
        ___qlistwidgetitem25->setText(QApplication::translate("MainWindow", "25", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem26 = listWidget_2->item(26);
        ___qlistwidgetitem26->setText(QApplication::translate("MainWindow", "26", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem27 = listWidget_2->item(27);
        ___qlistwidgetitem27->setText(QApplication::translate("MainWindow", "27", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem28 = listWidget_2->item(28);
        ___qlistwidgetitem28->setText(QApplication::translate("MainWindow", "28", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem29 = listWidget_2->item(29);
        ___qlistwidgetitem29->setText(QApplication::translate("MainWindow", "29", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem30 = listWidget_2->item(30);
        ___qlistwidgetitem30->setText(QApplication::translate("MainWindow", "30", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem31 = listWidget_2->item(31);
        ___qlistwidgetitem31->setText(QApplication::translate("MainWindow", "31", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem32 = listWidget_2->item(32);
        ___qlistwidgetitem32->setText(QApplication::translate("MainWindow", "32", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem33 = listWidget_2->item(33);
        ___qlistwidgetitem33->setText(QApplication::translate("MainWindow", "33", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem34 = listWidget_2->item(34);
        ___qlistwidgetitem34->setText(QApplication::translate("MainWindow", "34", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem35 = listWidget_2->item(35);
        ___qlistwidgetitem35->setText(QApplication::translate("MainWindow", "35", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem36 = listWidget_2->item(36);
        ___qlistwidgetitem36->setText(QApplication::translate("MainWindow", "36", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem37 = listWidget_2->item(37);
        ___qlistwidgetitem37->setText(QApplication::translate("MainWindow", "37", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem38 = listWidget_2->item(38);
        ___qlistwidgetitem38->setText(QApplication::translate("MainWindow", "38", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem39 = listWidget_2->item(39);
        ___qlistwidgetitem39->setText(QApplication::translate("MainWindow", "39", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem40 = listWidget_2->item(40);
        ___qlistwidgetitem40->setText(QApplication::translate("MainWindow", "40", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem41 = listWidget_2->item(41);
        ___qlistwidgetitem41->setText(QApplication::translate("MainWindow", "41", 0, QApplication::UnicodeUTF8));
        listWidget_2->setSortingEnabled(__sortingEnabled);

    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
