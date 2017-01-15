/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionExit;
    QAction *actionAbout;
    QAction *actionLoad_texture_now;
    QAction *actionRepaint_OpenGL;
    QAction *actionShow_hardware_Controls;
    QWidget *centralWidget;
    QGraphicsView *g1;
    QLabel *label;
    QLabel *name;
    QLabel *time;
    QLabel *sek;
    QLabel *training_title;
    QLabel *weight_label;
    QLabel *kg;
    QLabel *loops_counter;
    QGraphicsView *star;
    QLabel *hardware_controls_label;
    QLabel *sensor1;
    QLabel *lever_pos_2;
    QLabel *lever_pos;
    QGraphicsView *scroller_bgn;
    QGraphicsView *scroller_ticks;
    QLabel *clock;
    QLabel *training_progress;
    QLabel *training_status;
    QLabel *time_spent;
    QLabel *last_time;
    QLabel *target_time;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menu;
    QMenu *menuDebug;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1353, 785);
        MainWindow->setMinimumSize(QSize(1021, 785));
        MainWindow->setMaximumSize(QSize(1532, 785));
        MainWindow->setStyleSheet(QStringLiteral(""));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        actionLoad_texture_now = new QAction(MainWindow);
        actionLoad_texture_now->setObjectName(QStringLiteral("actionLoad_texture_now"));
        actionRepaint_OpenGL = new QAction(MainWindow);
        actionRepaint_OpenGL->setObjectName(QStringLiteral("actionRepaint_OpenGL"));
        actionShow_hardware_Controls = new QAction(MainWindow);
        actionShow_hardware_Controls->setObjectName(QStringLiteral("actionShow_hardware_Controls"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        g1 = new QGraphicsView(centralWidget);
        g1->setObjectName(QStringLiteral("g1"));
        g1->setGeometry(QRect(-2, -2, 1536, 768));
        g1->setStyleSheet(QStringLiteral("background-color: rgb(77, 77, 77);"));
        g1->setFrameShadow(QFrame::Plain);
        g1->setRenderHints(QPainter::Antialiasing|QPainter::HighQualityAntialiasing|QPainter::NonCosmeticDefaultPen|QPainter::Qt4CompatiblePainting|QPainter::SmoothPixmapTransform|QPainter::TextAntialiasing);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, -10, 381, 101));
        QFont font;
        font.setFamily(QStringLiteral("Segoe UI Semibold"));
        font.setPointSize(54);
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        font.setStyleStrategy(QFont::PreferAntialias);
        label->setFont(font);
        label->setStyleSheet(QStringLiteral("QLabel { color: rgb(255, 255, 255) }"));
        label->setScaledContents(false);
        name = new QLabel(centralWidget);
        name->setObjectName(QStringLiteral("name"));
        name->setGeometry(QRect(643, 16, 151, 61));
        QFont font1;
        font1.setFamily(QStringLiteral("Segoe UI Light"));
        font1.setPointSize(36);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        font1.setStyleStrategy(QFont::PreferAntialias);
        name->setFont(font1);
        name->setAutoFillBackground(false);
        name->setStyleSheet(QStringLiteral("QLabel { color: rgb(87, 129, 170) }"));
        name->setScaledContents(false);
        time = new QLabel(centralWidget);
        time->setObjectName(QStringLiteral("time"));
        time->setGeometry(QRect(453, 664, 81, 71));
        QFont font2;
        font2.setFamily(QStringLiteral("Segoe UI"));
        font2.setPointSize(48);
        font2.setBold(true);
        font2.setItalic(false);
        font2.setWeight(75);
        font2.setStyleStrategy(QFont::PreferAntialias);
        time->setFont(font2);
        time->setStyleSheet(QStringLiteral("QLabel { color: rgb(255, 255, 255) }"));
        time->setScaledContents(false);
        time->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        time->setMargin(5);
        sek = new QLabel(centralWidget);
        sek->setObjectName(QStringLiteral("sek"));
        sek->setGeometry(QRect(533, 686, 51, 51));
        QFont font3;
        font3.setFamily(QStringLiteral("Segoe UI Light"));
        font3.setPointSize(22);
        font3.setBold(false);
        font3.setItalic(false);
        font3.setWeight(50);
        font3.setStyleStrategy(QFont::PreferAntialias);
        sek->setFont(font3);
        sek->setStyleSheet(QStringLiteral("QLabel { color: rgb(255, 128, 0) }"));
        sek->setScaledContents(false);
        training_title = new QLabel(centralWidget);
        training_title->setObjectName(QStringLiteral("training_title"));
        training_title->setGeometry(QRect(9, 91, 361, 51));
        QFont font4;
        font4.setFamily(QStringLiteral("Segoe UI Semibold"));
        font4.setPointSize(24);
        font4.setBold(true);
        font4.setItalic(true);
        font4.setWeight(75);
        font4.setStyleStrategy(QFont::PreferAntialias);
        training_title->setFont(font4);
        training_title->setStyleSheet(QStringLiteral("QLabel { color: rgb(255, 255, 255) }"));
        training_title->setScaledContents(false);
        weight_label = new QLabel(centralWidget);
        weight_label->setObjectName(QStringLiteral("weight_label"));
        weight_label->setGeometry(QRect(871, 340, 101, 91));
        QFont font5;
        font5.setFamily(QStringLiteral("Segoe UI Semibold"));
        font5.setPointSize(60);
        font5.setBold(true);
        font5.setItalic(false);
        font5.setWeight(75);
        font5.setStyleStrategy(QFont::PreferAntialias);
        weight_label->setFont(font5);
        weight_label->setLayoutDirection(Qt::LeftToRight);
        weight_label->setStyleSheet(QStringLiteral("QLabel { color: rgb(193, 254, 255) }"));
        weight_label->setFrameShape(QFrame::NoFrame);
        weight_label->setLineWidth(0);
        weight_label->setTextFormat(Qt::RichText);
        weight_label->setScaledContents(false);
        weight_label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        weight_label->setMargin(0);
        weight_label->setIndent(0);
        kg = new QLabel(centralWidget);
        kg->setObjectName(QStringLiteral("kg"));
        kg->setGeometry(QRect(980, 386, 41, 51));
        QFont font6;
        font6.setFamily(QStringLiteral("Segoe UI Semibold"));
        font6.setPointSize(24);
        font6.setBold(true);
        font6.setItalic(false);
        font6.setWeight(75);
        font6.setStyleStrategy(QFont::PreferAntialias);
        kg->setFont(font6);
        kg->setMouseTracking(false);
        kg->setStyleSheet(QStringLiteral("QLabel { color: rgb(202, 221, 226) }"));
        kg->setFrameShadow(QFrame::Plain);
        kg->setTextFormat(Qt::AutoText);
        kg->setScaledContents(false);
        loops_counter = new QLabel(centralWidget);
        loops_counter->setObjectName(QStringLiteral("loops_counter"));
        loops_counter->setGeometry(QRect(890, 150, 101, 61));
        loops_counter->setFont(font1);
        loops_counter->setStyleSheet(QStringLiteral("QLabel { color: rgb(82, 91, 110) }"));
        loops_counter->setScaledContents(false);
        loops_counter->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        star = new QGraphicsView(centralWidget);
        star->setObjectName(QStringLiteral("star"));
        star->setGeometry(QRect(606, 36, 26, 26));
        star->setStyleSheet(QStringLiteral("background-image: url(:/p1/res/star.png);"));
        star->setFrameShape(QFrame::NoFrame);
        star->setFrameShadow(QFrame::Plain);
        star->setLineWidth(0);
        hardware_controls_label = new QLabel(centralWidget);
        hardware_controls_label->setObjectName(QStringLiteral("hardware_controls_label"));
        hardware_controls_label->setGeometry(QRect(1120, 10, 371, 61));
        hardware_controls_label->setFont(font4);
        hardware_controls_label->setAutoFillBackground(false);
        hardware_controls_label->setStyleSheet(QStringLiteral("QLabel { color: rgb(62, 91, 113) }"));
        hardware_controls_label->setScaledContents(false);
        sensor1 = new QLabel(centralWidget);
        sensor1->setObjectName(QStringLiteral("sensor1"));
        sensor1->setGeometry(QRect(1250, 100, 131, 61));
        QFont font7;
        font7.setFamily(QStringLiteral("Segoe UI"));
        font7.setPointSize(20);
        font7.setBold(false);
        font7.setItalic(false);
        font7.setWeight(50);
        font7.setStyleStrategy(QFont::PreferAntialias);
        sensor1->setFont(font7);
        sensor1->setAutoFillBackground(false);
        sensor1->setStyleSheet(QStringLiteral("QLabel { color: rgb(255, 255, 255) }"));
        sensor1->setScaledContents(false);
        lever_pos_2 = new QLabel(centralWidget);
        lever_pos_2->setObjectName(QStringLiteral("lever_pos_2"));
        lever_pos_2->setGeometry(QRect(1050, 280, 171, 61));
        QFont font8;
        font8.setFamily(QStringLiteral("Segoe UI"));
        font8.setPointSize(18);
        font8.setBold(true);
        font8.setItalic(true);
        font8.setWeight(75);
        font8.setStyleStrategy(QFont::PreferAntialias);
        lever_pos_2->setFont(font8);
        lever_pos_2->setAutoFillBackground(false);
        lever_pos_2->setStyleSheet(QStringLiteral("QLabel { color: rgb(255, 255, 255) }"));
        lever_pos_2->setScaledContents(false);
        lever_pos = new QLabel(centralWidget);
        lever_pos->setObjectName(QStringLiteral("lever_pos"));
        lever_pos->setGeometry(QRect(1070, 320, 111, 40));
        QFont font9;
        font9.setFamily(QStringLiteral("Segoe UI"));
        font9.setPointSize(20);
        font9.setBold(true);
        font9.setItalic(false);
        font9.setWeight(75);
        font9.setStyleStrategy(QFont::PreferAntialias);
        lever_pos->setFont(font9);
        lever_pos->setAutoFillBackground(false);
        lever_pos->setStyleSheet(QStringLiteral("QLabel { color: rgb(255, 255, 255) }"));
        lever_pos->setScaledContents(false);
        lever_pos->setAlignment(Qt::AlignCenter);
        scroller_bgn = new QGraphicsView(centralWidget);
        scroller_bgn->setObjectName(QStringLiteral("scroller_bgn"));
        scroller_bgn->setGeometry(QRect(1270, 210, 41, 434));
        scroller_bgn->setStyleSheet(QStringLiteral("background-image: url(:/p1/res/scroller.png);"));
        scroller_bgn->setFrameShape(QFrame::NoFrame);
        scroller_bgn->setFrameShadow(QFrame::Plain);
        scroller_bgn->setLineWidth(0);
        scroller_ticks = new QGraphicsView(centralWidget);
        scroller_ticks->setObjectName(QStringLiteral("scroller_ticks"));
        scroller_ticks->setGeometry(QRect(1318, 203, 117, 448));
        scroller_ticks->setStyleSheet(QStringLiteral("background-image: url(:/p1/res/stripes.png);"));
        scroller_ticks->setFrameShape(QFrame::NoFrame);
        scroller_ticks->setFrameShadow(QFrame::Plain);
        scroller_ticks->setLineWidth(0);
        clock = new QLabel(centralWidget);
        clock->setObjectName(QStringLiteral("clock"));
        clock->setGeometry(QRect(380, 671, 60, 60));
        training_progress = new QLabel(centralWidget);
        training_progress->setObjectName(QStringLiteral("training_progress"));
        training_progress->setGeometry(QRect(195, 635, 826, 15));
        training_progress->setStyleSheet(QStringLiteral("background-image: url(:/p1/res/progress.png);"));
        training_status = new QLabel(centralWidget);
        training_status->setObjectName(QStringLiteral("training_status"));
        training_status->setGeometry(QRect(0, 635, 195, 130));
        QFont font10;
        font10.setFamily(QStringLiteral("Segoe UI"));
        font10.setPointSize(28);
        font10.setBold(true);
        font10.setWeight(75);
        training_status->setFont(font10);
        training_status->setStyleSheet(QLatin1String("background-color: rgb(185, 229, 34);\n"
"color:rgb(48,53,62);"));
        training_status->setTextFormat(Qt::RichText);
        training_status->setScaledContents(false);
        training_status->setAlignment(Qt::AlignCenter);
        time_spent = new QLabel(centralWidget);
        time_spent->setObjectName(QStringLiteral("time_spent"));
        time_spent->setGeometry(QRect(1050, 460, 201, 61));
        QFont font11;
        font11.setFamily(QStringLiteral("Segoe UI"));
        font11.setPointSize(16);
        font11.setBold(true);
        font11.setItalic(true);
        font11.setWeight(75);
        font11.setStyleStrategy(QFont::PreferAntialias);
        time_spent->setFont(font11);
        time_spent->setAutoFillBackground(false);
        time_spent->setStyleSheet(QStringLiteral("QLabel { color: rgb(255, 255, 255) }"));
        time_spent->setScaledContents(false);
        last_time = new QLabel(centralWidget);
        last_time->setObjectName(QStringLiteral("last_time"));
        last_time->setGeometry(QRect(1050, 490, 201, 61));
        last_time->setFont(font11);
        last_time->setAutoFillBackground(false);
        last_time->setStyleSheet(QStringLiteral("QLabel { color: rgb(255, 255, 255) }"));
        last_time->setScaledContents(false);
        target_time = new QLabel(centralWidget);
        target_time->setObjectName(QStringLiteral("target_time"));
        target_time->setGeometry(QRect(1050, 520, 201, 61));
        target_time->setFont(font11);
        target_time->setAutoFillBackground(false);
        target_time->setStyleSheet(QStringLiteral("QLabel { color: rgb(255, 255, 255) }"));
        target_time->setScaledContents(false);
        MainWindow->setCentralWidget(centralWidget);
        g1->raise();
        label->raise();
        name->raise();
        time->raise();
        sek->raise();
        training_title->raise();
        kg->raise();
        loops_counter->raise();
        star->raise();
        hardware_controls_label->raise();
        sensor1->raise();
        lever_pos_2->raise();
        lever_pos->raise();
        scroller_bgn->raise();
        scroller_ticks->raise();
        clock->raise();
        training_progress->raise();
        training_status->raise();
        weight_label->raise();
        time_spent->raise();
        last_time->raise();
        target_time->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1353, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menuDebug = new QMenu(menuBar);
        menuDebug->setObjectName(QStringLiteral("menuDebug"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuDebug->menuAction());
        menuBar->addAction(menu->menuAction());
        menuFile->addAction(actionShow_hardware_Controls);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menu->addAction(actionAbout);
        menuDebug->addAction(actionLoad_texture_now);
        menuDebug->addAction(actionRepaint_OpenGL);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Egym demo1", Q_NULLPTR));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", Q_NULLPTR));
        actionAbout->setText(QApplication::translate("MainWindow", "About", Q_NULLPTR));
        actionLoad_texture_now->setText(QApplication::translate("MainWindow", "Load texture now", Q_NULLPTR));
        actionRepaint_OpenGL->setText(QApplication::translate("MainWindow", "Repaint OpenGL", Q_NULLPTR));
        actionShow_hardware_Controls->setText(QApplication::translate("MainWindow", "Show Hardware Controls", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Ruderzug", Q_NULLPTR));
        name->setText(QApplication::translate("MainWindow", "Sandro", Q_NULLPTR));
        time->setText(QApplication::translate("MainWindow", "59", Q_NULLPTR));
        sek->setText(QApplication::translate("MainWindow", "sek", Q_NULLPTR));
        training_title->setText(QApplication::translate("MainWindow", "Muskelaufbau - Negativ", Q_NULLPTR));
        weight_label->setText(QApplication::translate("MainWindow", "1", Q_NULLPTR));
        kg->setText(QApplication::translate("MainWindow", "kg", Q_NULLPTR));
        loops_counter->setText(QApplication::translate("MainWindow", "x0", Q_NULLPTR));
        hardware_controls_label->setText(QApplication::translate("MainWindow", "HARDWARE CONTROLS", Q_NULLPTR));
        sensor1->setText(QApplication::translate("MainWindow", "Sensor 1", Q_NULLPTR));
        lever_pos_2->setText(QApplication::translate("MainWindow", "Lever position", Q_NULLPTR));
        lever_pos->setText(QApplication::translate("MainWindow", "50.00%", Q_NULLPTR));
        clock->setText(QString());
        training_progress->setText(QString());
        training_status->setText(QApplication::translate("MainWindow", "Ready", Q_NULLPTR));
        time_spent->setText(QApplication::translate("MainWindow", "time", Q_NULLPTR));
        last_time->setText(QApplication::translate("MainWindow", "last time 0ms", Q_NULLPTR));
        target_time->setText(QApplication::translate("MainWindow", "over time 0ms", Q_NULLPTR));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", Q_NULLPTR));
        menu->setTitle(QApplication::translate("MainWindow", "?", Q_NULLPTR));
        menuDebug->setTitle(QApplication::translate("MainWindow", "Debug", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
