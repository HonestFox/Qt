#include <QPaintEvent>
#include <QPainter.h>
#include <cmath>
#include "MySin.h"
#include "AfGbk.h"

MySin::MySin(QWidget *parent)
	: QFrame(parent)
	,m_grain(1)
	,m_period(100)
	,m_radius(200)
{
// 	m_ui = new Test11_8a_12_13();
// 	string StrPeriod = AfGbk::FromUnicode(m_ui->GetPeriod());
// 	string StrGrain = AfGbk::FromUnicode(m_ui->GetGrain());
// 	string StrRadius = AfGbk::FromUnicode(m_ui->GetRadius());
// 	m_period = atoi(StrPeriod.c_str());
// 	m_radius = atoi(StrRadius.c_str());
// 	m_grain = atoi(StrGrain.c_str());

}

MySin::~MySin()
{

}


void MySin::paintEvent(QPaintEvent* event)
{
	if (m_grain == 0)
	{
		return;
	}

	QPainter painter(this);
	int width = this->width();
	int height = this->height();
	QRect rect(0, 0, width, height);

	//画背景（黑色）
	painter.setBrush(QColor(0, 0, 0));
	painter.drawRect(rect);

	//设置线条颜色 （白色）
	painter.setPen(QPen(QColor(255, 255, 255)));

	//画中间基准线
	QPoint o = origin();
	painter.drawLine(QPoint(0, o.y()), QPoint(width, o.y()));
	painter.drawLine(QPoint(o.x(), 0), QPoint(o.x(), height));

	
	painter.setPen(QPen(QColor(0, 255, 0)));



	//正弦曲线：从坐标原点，向左、右伸展
	QPoint p1(0, 0);
	for (int x = 0; x < width / 2; x += m_grain)
	{
		double angle = (double)x / m_period * 2 * 3.1415926;
		double y = m_radius * sin(angle);
		QPoint p2(x, y);
		//左
		painter.drawLine(fromCoord(p1), fromCoord(p2));
		//右
		QPoint base(0, 0);
		painter.drawLine(fromCoord(base - p1), fromCoord(base - p2));
		p1 = p2;
	}

}

void MySin::Adjust(int period, int grain, int radius)
{
	m_period = period;
	m_grain = grain;
	m_radius = radius;
	update();
}

QPoint MySin::origin()
{
	QRect r = this->rect();
	return r.center();
}

//将GUI窗口的点（x,y）转换成坐标系统里的点
QPoint MySin::toCoord(QPoint p)
{
	//圆心
	QPoint o = this->origin();
	QPoint result = p - o;
	result.setY(0 - result.y());	//Y坐标反转
	return result;
}

//将坐标系内的点(x,y)转换成GUI坐标
QPoint MySin::fromCoord(QPoint p)
{
	//圆心
	QPoint o = this->origin();
	p.setY(0 - p.y());
	return p + o;
}


