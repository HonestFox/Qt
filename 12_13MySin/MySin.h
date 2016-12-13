#pragma once

#include <QFrame>
#include <QPoint>

class MySin : public QFrame
{
	Q_OBJECT

public:
	MySin(QWidget *parent);
	~MySin();

	void Adjust(int period, int grain, int radius);

	//坐标原点
	QPoint origin();
	//将GUI窗口的点（x,y）转换成坐标系统里的点
	QPoint toCoord(QPoint p);
	//将坐标系内的点(x,y)转换成GUI坐标
	QPoint fromCoord(QPoint p);

private:
	virtual void paintEvent(QPaintEvent* event);

private:
	int m_period;	//周期
	int m_grain;		//粒度
	int m_radius;	//幅度
	//Test11_8a_12_13* m_ui;
};
