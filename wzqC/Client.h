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
    //���ӷ�����
    QTcpSocket* tcpSocket_server;

    //��Ϸ��������
    ServerStatus serverStatus;

    //��ʼ���ؼ�����
    void widgetInit();

private slots:
    void on_conn_client_BTN_clicked();

    //���ӷ������ɹ�
    void connSuccessful();
    //���ӷ�����ʧ��
    void connFailed();
    //�����Ͽ�����
    void disconnection();



};
