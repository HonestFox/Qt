#pragma once

#include <QDialog>
#include "ui_SendDlg.h"
#include "SendTask.h"


class SendDlg : public QDialog
{
	Q_OBJECT

public:
	SendDlg(const QString& filepath, QWidget *parent = Q_NULLPTR);
	~SendDlg();
	virtual void timerEvent(QTimerEvent* event);
private:
	Ui::SendDlg ui;
	SendTask* m_task;		//工作线程

	int m_timerid;
};
