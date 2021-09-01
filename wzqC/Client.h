#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Client.h"
#include "ServerStatus.h"
#include "GameStatus.h"
#include <QTcpSocket>
#include <QMessageBox>
#include "DataClass.h"



class Client : public QMainWindow
{
    
    Q_OBJECT

public:
    Client(QWidget *parent = Q_NULLPTR);

private:
    Ui::ClientClass ui;
    //连接服务器
    QTcpSocket* tcpSocket_server;

    //游戏大厅窗口
    ServerStatus serverStatus;

    //初始化控件属性
    void widgetInit();

private slots:
    void on_conn_client_BTN_clicked();

    //连接服务器成功
    void connSuccessful();
    //连接服务器失败
    void connFailed();
    //主动断开连接
    void disconnection();



};
