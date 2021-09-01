#include "DataClass.h"


const QRegExp DataClass::regPort = QRegExp("([1-9])|([1-9]\\d{3})|([1-5]\\d{4})|(6[1-4]\\d{3})|(65[1-4]\\d{2})|(655[1-2]\\d)|(6553[1-5])");
const QRegExp DataClass::regIP = QRegExp("([1-9]|[1-9]\\d|1\\d{2}|2[0-4]\\d|25[0-5])(\\.(\\d|[1-9]\\d|1\\d{2}|2[0-4]\\d|25[0-5])){3}");
const QRegExp DataClass::regConnLimit = QRegExp("([0-9]|[1-9][0-9]{2})");


int DataClass::connPort = -1;

QString DataClass::nickName = QString("aaa");

bool DataClass::checkDialog(QString title, QString context)
{
	QMessageBox msgBox(title, context, QMessageBox::Question, QMessageBox::Yes | QMessageBox::Default, QMessageBox::No | QMessageBox::Escape, QMessageBox::NoButton);

	if (msgBox.exec() == QMessageBox::No)
		return false;
	else
		return true;
}

void DataClass::sendMsg(comm_request_type type, QString context, QTcpSocket* _tcpSocket)
{
	msg_request_struct msg_req_struct;
	msg_req_struct.request = type;
	msg_req_struct.data = context;

	QByteArray buff;
	QDataStream out(&buff, QIODevice::WriteOnly);
	out << msg_req_struct.request << msg_req_struct.data;
	_tcpSocket->write(buff);
}




void DataClass::dbgBox(int lPara, int rPara)
{
	QMessageBox::information(NULL, QString::number(lPara), QString::number(rPara));
}

void DataClass::dbgBox(int lPara, QString rPara)
{
	QMessageBox::information(NULL, QString::number(lPara), rPara);
}

void DataClass::dbgBox(QString lPara, QString rPara)
{
	QMessageBox::information(NULL, lPara, rPara);
}




