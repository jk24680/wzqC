#pragma once

#include <QWidget>
#include "ui_ServerStatus.h"
#include "GameStatus.h"
#include <QTcpSocket>
#include "DataClass.h"



class ServerStatus : public QWidget
{
	Q_OBJECT

public:
	ServerStatus(QWidget *parent = Q_NULLPTR);
	~ServerStatus();

	//设置参数
	void setPara(QTcpSocket* _tcpSocket_server);

	//设置昵称?这个暂时不写
	//void connClosedByServer();

	//服务器关闭
	void connClosedByServer();

private:
	Ui::ServerStatus ui;

	//游戏界面
	GameStatus gameStatus;
	//玩家对战状态
	QList<QPair<QString, QString>>playerFightInfo;
	//数据包申明
	msg_request_struct* msg_req_struct;
	//交互服务器的socket
	QTcpSocket* tcpSocket_server;
	//设置游戏大厅信息
	void setGameInfo(QString& data);

private slots:
	//双击别人的主机然后加入方法
	void on_clientStatus_client_TBW_itemDoubleClicked(QTableWidgetItem*);
	//收到新数据
	void getNewData();
	//创建主机按钮
	void on_create_client_BTN_clicked();
	//退出游戏按钮
	void on_quit_client_BTN_clicked();

signals:
	void disconnection();

protected:
	void closeEvent(QCloseEvent*);

};
