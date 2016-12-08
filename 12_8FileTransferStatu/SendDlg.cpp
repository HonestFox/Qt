#include <QTimerEvent>
#include "SendDlg.h"
#include "AfGbk.h"

SendDlg::SendDlg(const QString& filepath, QWidget *parent /*= Q_NULLPTR*/)
{
		ui.setupUi(this);
		//创建工作线程
		m_task = new SendTask(NULL);
		m_task->CreateTask(AfGbk::FromUnicode(filepath).c_str());
		m_timerid = startTimer(50);
}



SendDlg::~SendDlg()
{
}

void SendDlg::timerEvent(QTimerEvent* event)
{
	if (event->timerId() == m_timerid)
	{
		//获取工作线程的当前状态
		int status = m_task->GetStatus();
		int progress = m_task->GetProgress();

		ui.progressBar->setValue(progress);
		if (status == 1)
		{
			//收尾工作
			killTimer(m_timerid);	//关闭定时器
			this->accept();				//关闭对话框
			m_task->Destroy();
			delete m_task;
		}

	}
}
