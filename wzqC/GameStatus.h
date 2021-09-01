#pragma once

#include <QWidget>
#include "ui_GameStatus.h"
#include <QTcpSocket>
#include "DataClass.h"
#include <QtNetwork/qtcpserver.h>
#include <QPainter>
#include <qtimer.h>


class GameStatus : public QWidget
{
	
    Q_OBJECT

public:
	GameStatus(QWidget *parent = Q_NULLPTR);
	~GameStatus();

	//设置参数
	void setPara(QTcpSocket* _tcpSocket_server);
	//设置对手信息
	void setPlayerInfo(QString rivarAddr);
	//设置当前进入游戏身份 主机？
	void setPlayerRole(playerRole _plyRole);

private slots:
   // void on_lose_client_BTN_clicked();
   // void on_undo_client_BTN_clicked();
    void on_send_client_BTN_clicked();
    void on_quit_client_BTN_clicked();
    void on_gameReady_client_BTN_clicked();

    //从服务器收到数据
    void getNewDataFromServer();
    //从对手连接收到数据
    void getNewDataFromClient();

    //收到对方玩家的连接请求
    void getNewConn();
    //和对方玩家建立连接成功
    void connSuccessful();
    //和对方玩家建立连接失败
    void connFailed();

    ////对方超时
    //void timeout();


protected:
    //响应关闭事件
    void closeEvent(QCloseEvent* event);

    //重绘事件
    void paintEvent(QPaintEvent* event);

    //鼠标按下事件
    void mousePressEvent(QMouseEvent*);


private:
	Ui::GameStatus ui;

    //初始化数据
    void dataInit();
    //记录当前整个棋盘的信息
    int chessboardRecord[19][19];

    //关闭信息是从服务器发来的？
    bool closeByServer;

    //数据包结构
    msg_request_struct* msg_req_struct;

    //当前身份，主机？
    playerRole plyRole;

    //当前游戏状态
    playerStatus plyStatus;

    //下一步该谁走?
    playerRole whosTurn;

    //双方对战成绩
    int win, lose;

    //记录当前已经落下的棋子
    QList<QPair<QPoint, enum playerRole> > pieceRecord;

    //棋子直径
    static const int pieceSize;

    //游戏网格个数  m x m
    static const int gameCellCount;
    //单元网格大小
    static const int gameCellSize;

    //画图偏移量，横向和纵向
    static const int paintOffset_W;
    static const int paintOffset_H;

    //鼠标位置偏移量，横向和纵向
    static const int mouseMoveOffset_W;
    static const int mouseMoveOffset_H;

    //画鼠标范围框偏移
    static const int halfCellWidth;
    static const int frameWidth;

    //每个五子棋小方框的高宽
    static const int paneWidth;
    static const int paneHeight;

    //用于交互服务器
    QTcpSocket* tcpSocket_server;

    //用户玩家之间落子，发信息的TCP，交流双方一方为tpcServer，一方为tcpSocket
    QTcpServer* tcpServer_player;
    QTcpSocket* tcpSocket_player;

    //初始化控件属性
    void widgetInit();

    //收到信息
    void recvMsg_quitGame();
    void recvMsg_gameStart();
    void recvMsg_gameOP();
    void recvMsg_lose();
    void recvMsg_gameOver();
    void recvMsg_chat();
   /* void recvMsg_undo();
    void recvMsg_undoYes();
    void recvMsg_undoNo();*/

    //判断是否胜利
    //八个方向
    bool checkWin();
    bool checkWinLURD(int last_x, int last_y, int winColor);
    bool checkWinUD(int last_x, int last_y, int winColor);
    bool checkWinRULD(int last_x, int last_y, int winColor);
    bool checkWinRL(int last_x, int last_y, int winColor);

    //画鼠标周围的方框
    void drawMouseArea(QPainter* painter);
    //画网格
    void drawGrid(QPainter* painter);
    //画棋子
    void drawPieceRecord(QPainter* painter);
    //设置超时信息的定时器
   // QTimer *timer=new QTimer();
};
