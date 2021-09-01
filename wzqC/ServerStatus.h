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

	//���ò���
	void setPara(QTcpSocket* _tcpSocket_server);

	//�����ǳ�?�����ʱ��д
	//void connClosedByServer();

	//�������ر�
	void connClosedByServer();

private:
	Ui::ServerStatus ui;

	//��Ϸ����
	GameStatus gameStatus;
	//��Ҷ�ս״̬
	QList<QPair<QString, QString>>playerFightInfo;
	//���ݰ�����
	msg_request_struct* msg_req_struct;
	//������������socket
	QTcpSocket* tcpSocket_server;
	//������Ϸ������Ϣ
	void setGameInfo(QString& data);

private slots:
	//˫�����˵�����Ȼ����뷽��
	void on_clientStatus_client_TBW_itemDoubleClicked(QTableWidgetItem*);
	//�յ�������
	void getNewData();
	//����������ť
	void on_create_client_BTN_clicked();
	//�˳���Ϸ��ť
	void on_quit_client_BTN_clicked();

signals:
	void disconnection();

protected:
	void closeEvent(QCloseEvent*);

};
