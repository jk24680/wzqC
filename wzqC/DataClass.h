#pragma once

#include <QtWidgets/QMainWindow>
#include <QTcpSocket>
#include <QMessageBox>
#include <QCloseEvent>
#include <QDataStream>

enum playerRole
{
	//��¼�������ķ���
	HOST,
	GUEST
};

enum playerStatus
{
	//��¼��ǰ��������Ϸ���ǵȴ��У�����δ��ʼ
	playingGame,
	readyToPlayingGame
};


enum comm_request_type
{
	//���ӷ�����ʧ��0
	COMM_SERVER_CONN_FAILED,
	//���ӷ������ɹ�1
	COMM_SERVER_CONN_SUCCESSFUL,
	//�������ر�2
	COMM_SERVER_CLOSE,
	//���������ʹ�����Ϣ3
	COMM_SERVER_GAMEINFO,
    //�˳���Ϸ4
    COMM_CLIENT_QUITGAME,
    //����Ͽ�������5
    COMM_CLIENT_DISCONN,
    //�ͻ����������ӷ�����6
    COMM_CLIENT_CONN,
    //�ͻ������󴴽�����7
    COMM_CLIENT_CREATE,
    //�ͻ������������Ϸ8
    COMM_CLIENT_JOIN,
    //˫��׼����ϣ���Ϸ��ʼ9
    COMM_CLIENT_GAMESTART,
    //ĳ�����ʤ������Ϸ����10
    COMM_CLIENT_GAMEOVER,
    //�����Ϸ����������11
    COMM_CLIENT_GAMEOP,
    //�����Ϸ����������������Ϣ12
    COMM_CLIENT_CHAT,
    //�����Ϸ����������13
    COMM_CLIENT_UNDO,
    //�����Ϸ����������ظ�yes14
    COMM_CLIENT_UNDO_YES,
    //�����Ϸ����������ظ�no15
    COMM_CLIENT_UNDO_NO,
    //�����Ϸ����������16
    COMM_CLIENT_LOSE,
    //��ҷ�����Ϣ���Է�����17
    COMM_CLIENT_LOSTCONN
};


struct msg_request_struct
{
    qint8 request;
    QString data;
};


class DataClass
{
    public:
        //�û��ǳƣ��Ƿ��õ���
        static QString nickName;
        //����ˣ��ͻ�����Ҫ���ӵ��Ķ˿�
        static int connPort;
        //������ʽ���˿ڣ�IP,����
        static const QRegExp regPort;
        static const QRegExp regIP;
        static const QRegExp regConnLimit;

        //ȷ�϶Ի���
        static bool checkDialog(QString title, QString context);

            //debug messagebox�������ʲô��
            static void dbgBox(int lPara, int rPara);
        static void dbgBox(int lPara, QString rPara);
        static void dbgBox(QString lPara, QString rPara);
           
        //��������
        static void sendMsg(comm_request_type type, QString context, QTcpSocket* _tcpSocket);
};

