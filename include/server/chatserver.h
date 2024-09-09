#pragma once
#include<muduo/net/TcpServer.h>
#include<muduo/net/EventLoop.h>
#include<string>
using namespace muduo;
using namespace muduo::net;

class ChatServer
{
public:
	//��ʼ���������������
	ChatServer(EventLoop* loop,
		const InetAddress& listenAddr,
		const std::string& nameArg);

	//��������
	void start();
private:

	//�ϱ����������Ϣ�Ļص�����
	void onConnection(const TcpConnectionPtr&);

	//�ϱ���д�¼������Ϣ�Ļص�����
	void onMessage(const TcpConnectionPtr&,
		Buffer*,
		Timestamp);

	TcpServer _server;
	EventLoop* _loop;
};
