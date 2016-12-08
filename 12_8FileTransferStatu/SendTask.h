#pragma once

#include <QThread>

class SendTask : public QThread
{
	Q_OBJECT

public:
	SendTask(QObject *parent);
	~SendTask();
public:
	int CreateTask(const char* filename);
	int Destroy();
	

	int GetProgress();
	int GetStatus();
private:
	void run();

private:
	char m_filepath[128];
	int m_filesize;		//文件的总字节数
	int m_bytesread;	//读取并处理的字节数
	int m_status;		//任务状态
};
