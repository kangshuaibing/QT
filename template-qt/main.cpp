﻿#if _MSC_VER >=1600
#pragma execution_character_set("utf-8")
#endif

#include "gui/CentralWidget.h"
#include "gui/CentralWidget2.h"
#include "gui/TopWindow.h"
#include "gui/LoginWidget.h"
#include "util/UiUtil.h"
#include "util/LogHandler.h"

#include <QApplication>
#include <QTextCodec>
#include <QDir>

static void initialize(); // 程序启动时进行初始化
static void finalize();   // 程序结束时清理工作



int main(int argc, char *argv[]) {
    // 启用 Retina 高分辨率
    QApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);
    QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication app(argc, argv);
    ::initialize();


    // [1] 主窗口使用自定义窗口显示: 2 种风格
    // 风格 1
    CentralWidget *cw = new CentralWidget();
    TopWindow window(cw);
    window.setTitle("普通窗口"); // 默认使用 CentralWidget 的 windowTitle
    window.resize(1000, 700);
    //UiUtil::centerWindow(&window);
    window.show();

    // 风格 2
//    CentralWidget2 *cw = new CentralWidget2();
//    TopWindow window(cw);
//    cw->twitterUi(&window);
//    window.resize(1000, 700);
//    UiUtil::showCenter(&window);

    // [2] 显示登陆对话框，点击取消按钮登陆失败退出程序，登陆成功继续往下运行
    // 输入错误信息虽然登陆不成功，但是不会退出程序，而是提示输入错误，继续输入登陆
//    if (!LoginWidget::login()) {
//        exit(0);
//    }

    // [3] 进入 Qt 事件队列
    int code = app.exec();

    // [4] 程序退出时善后处理
    ::finalize();

    return code;
}


/**
 * 程序启动时进行初始化
 */
static void initialize() {
    // 使用 UTF-8 的运行时环境
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));

    // 安装日志处理工具
    LogHandlerInstance.installMessageHandler();

    // 今后访问相对路径的文件，则是相对于可执行文件所在目录了，而不是系统的根目录
    QDir::setCurrent(QCoreApplication::applicationDirPath());

    // 设置界面样式
    UiUtil::loadQss();

    // 加载字体
    UiUtil::loadFonts();
}

/**
 * 程序结束时清理工作
 * 程序结束时释放回收资源，例如释放日志资源，释放数据库连接池资源等
 */
static void finalize() {
    LogHandlerInstance.uninstallMessageHandler(); // 程序结束时释放 LogHandler 的资源，例如刷新并关闭日志文件
}
