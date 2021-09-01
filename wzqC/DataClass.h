#pragma once

#include <QtWidgets/QMainWindow>
#include <QTcpSocket>
#include <QMessageBox>
#include <QCloseEvent>
#include <QDataStream>

enum playerRole
{
	//记录棋子由哪方下
	HOST,
	GUEST
};

enum playerStatus
{
	//记录当前是正在游戏还是等待中，房间未开始
	playingGame,
	readyToPlayingGame
};


enum comm_request_type
{
	//连接服务器失败0
	COMM_SERVER_CONN_FAILED,
	//连接服务器成功1
	COMM_SERVER_CONN_SUCCESSFUL,
	//服务器关闭2
	COMM_SERVER_CLOSE,
	//服务器发送大厅信息3
	COMM_SERVER_GAMEINFO,
    //退出游戏4
    COMM_CLIENT_QUITGAME,
    //请求断开服务器5
    COMM_CLIENT_DISCONN,
    //客户端请求连接服务器6
    COMM_CLIENT_CONN,
    //客户端请求创建主机7
    COMM_CLIENT_CREATE,
    //客户端请求加入游戏8
    COMM_CLIENT_JOIN,
    //双方准备完毕，游戏开始9
    COMM_CLIENT_GAMESTART,
    //某方玩家胜利，游戏结束10
    COMM_CLIENT_GAMEOVER,
    //玩家游戏操作：落子11
    COMM_CLIENT_GAMEOP,
    //玩家游戏操作：发送聊天信息12
    COMM_CLIENT_CHAT,
    //玩家游戏操作：悔棋13
    COMM_CLIENT_UNDO,
    //玩家游戏操作：悔棋回复yes14
    COMM_CLIENT_UNDO_YES,
    //玩家游戏操作：悔棋回复no15
    COMM_CLIENT_UNDO_NO,
    //玩家游戏操作：认输16
    COMM_CLIENT_LOSE,
    //玩家发来消息，对方掉线17
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
        //用户昵称？是否用的着
        static QString nickName;
        //服务端，客户端需要连接到的端口
        static int connPort;
        //正则表达式：端口，IP,整数
        static const QRegExp regPort;
        static const QRegExp regIP;
        static const QRegExp regConnLimit;

        //确认对话框
        static bool checkDialog(QString title, QString context);

            //debug messagebox？这个有什么用
            static void dbgBox(int lPara, int rPara);
        static void dbgBox(int lPara, QString rPara);
        static void dbgBox(QString lPara, QString rPara);
           
        //发送数据
        static void sendMsg(comm_request_type type, QString context, QTcpSocket* _tcpSocket);
};

