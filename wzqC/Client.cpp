#include "Client.h"

Client::Client(QWidget *parent)
    : QMainWindow(parent), serverStatus(NULL), tcpSocket_server(NULL)
{
    ui.setupUi(this);
}

void Client::widgetInit()
{
    ui.serverAddr_client_LE->setValidator(new QRegExpValidator(DataClass::regIP, this));
    ui.serverPort_client_LE->setValidator(new QRegExpValidator(DataClass::regPort, this));
}

void Client::connSuccessful()
{
    this->hide();

    //DataClass::nickName = ui.nickName_client_LE->text();
    DataClass::connPort = ui.serverPort_client_LE->text().toInt();
    //���ò���
    serverStatus.setPara(tcpSocket_server);
    //�����Ͽ�����
    connect(&serverStatus, SIGNAL(disconnection()), this, SLOT(disconnection()));
    //���ܵ������ݹ���
    connect(tcpSocket_server, SIGNAL(readyRead()), &serverStatus, SLOT(getNewData()));
    serverStatus.show();
    return;
}

void Client::connFailed()
{
    serverStatus.connClosedByServer();
    serverStatus.hide();
    this->show();
    QMessageBox::information(this, QString::fromLocal8Bit("��ʾ"), QStringLiteral("����ʧ��"));
    return;
}

void Client::disconnection()
{
   
        serverStatus.hide();
        this->show();
        return;
    
}


void Client::on_conn_client_BTN_clicked()
{
    if ( ui.serverAddr_client_LE->text() == "" || ui.serverPort_client_LE->text() == "")
    {
        QMessageBox::information(this, "����", "�������������Ϣ��");
        return;
    }

    tcpSocket_server = new QTcpSocket(this);
    tcpSocket_server->connectToHost(ui.serverAddr_client_LE->text(), ui.serverPort_client_LE->text().toInt());
    //���ӳɹ�
    connect(tcpSocket_server, SIGNAL(connected()), this, SLOT(connSuccessful()));
    //���ӳ���
    connect(tcpSocket_server, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(connFailed()));


}

