#include <QMouseEvent>
#include <QColor>
#include <QPainter>
#include "MySlider.h"

MySlider::MySlider(QWidget *parent)
	: QFrame(parent)
	, m_focused(false)
	, m_pressed(false)
	,m_range(100)
	,m_progress(0)
	, m_virtual_progress(0)
{
	setMouseTracking(true);
	setCursor(Qt::PointingHandCursor);		//鼠标：手型
}

MySlider::~MySlider()
{
}

void MySlider::setRange(int range)
{
	m_range = range;
	update();
}

void MySlider::setProgres(int progress)
{
	m_progress = progress;
	update();
}

int MySlider::range() const
{
	return m_range;
}
int MySlider::progress() const
{
	return m_progress;
}

QSize MySlider::sizeHint() const
{
	return QSize();
}

//鼠标移入
void MySlider::enterEvent(QEvent* event)
{
	m_focused = true;
	update();
	emit focused(true);
	QWidget::enterEvent(event);
}

//鼠标移出
void MySlider::leaveEvent(QEvent *event)
{
	m_focused = false;
	update();
	emit focused(false);
	QWidget::leaveEvent(event);
}

void MySlider::mouseMoveEvent(QMouseEvent *event)
{
	int progress = PosToProg(event->pos().x());
	emit tracking(progress, event->pos());
	QWidget::mouseMoveEvent(event);
	if(m_pressed)
	{
		m_virtual_progress = progress;
		update();
	}

}

void MySlider::mousePressEvent(QMouseEvent *event)
{
	if (event->button() == Qt::LeftButton)	//左键
	{
		m_pressed = true;
	}
}

void MySlider::mouseReleaseEvent(QMouseEvent *event)
{
	if (m_pressed)
	{
		m_pressed = false;
		m_progress = PosToProg(event->pos().x());
		update();
		emit clicked(m_progress);
	}
}

void MySlider::paintEvent(QPaintEvent* event)
{
	QPainter painter(this);
	painter.setRenderHint(QPainter::Antialiasing);	//抗锯齿

	int width = this->width() - 20;
	int height = this->height();
	int vcenter = height / 2;
	int xoff = 0;

	QColor colorLeft = QColor(44, 143, 214);
	QColor colorRight = QColor(0x888888);
	QColor colorHandle = QColor(51, 153, 255);
	QColor colorHandleFrame = QColor(0xCCCCCC);

	int position = xoff + m_progress * width / m_range;

	if (!m_focused)		//没有被选中的状态
	{
		//细线模式
		QPen pen;
		pen.setWidth(2);	//线宽
		
		//左半段
		pen.setColor(colorLeft);
		painter.setPen(pen);
		painter.drawLine(QPoint(0, vcenter), QPoint(position, vcenter));

		//右半段
		pen.setColor(colorRight);
		painter.setPen(pen);
		painter.drawLine(QPoint(position, vcenter), QPoint(width, vcenter));

		//小圆球
		pen.setWidth(1);
		pen.setColor(colorHandleFrame);
		painter.setPen(pen);
		painter.setBrush(colorHandle);
		painter.drawEllipse(QPoint(position + 5, vcenter), 5, 5);
	}

	else
	{
		//粗线模式
		QPen pen;
		pen.setWidth(4);	// 线宽
		//vcenter -= 4;

		//左半段
		pen.setColor(colorLeft);
		painter.setPen(pen);
		painter.drawLine(QPoint(0, vcenter), QPoint(position, vcenter));

		//右半段
		pen.setColor(colorRight);
		painter.setPen(pen);
		painter.drawLine(QPoint(position, vcenter), QPoint(width, vcenter));

		//手柄（圆角矩形）
		pen.setWidth(1);
		pen.setColor(colorHandleFrame);
		painter.setPen(pen);
		painter.setBrush(colorHandle);

		int w = 20;
		int h = 10;
		QRect rectHandle(position, vcenter - h / 2, w, h);
		painter.drawRoundedRect(rectHandle, 4, 4);
	}

	if (m_pressed)	//拖动
	{
		//粗线模式
		QPen pen;
		pen.setWidth(4);	// 线宽

		int virtual_pos = ProgToPos(m_virtual_progress);

		//左半段
		pen.setColor(colorLeft);
		painter.setPen(pen);
		painter.drawLine(QPoint(0, vcenter), QPoint(virtual_pos, vcenter));

		//右半段
		pen.setColor(colorRight);
		painter.setPen(pen);
		painter.drawLine(QPoint(virtual_pos, vcenter), QPoint(width, vcenter));

		//手柄
		pen.setWidth(1);
		pen.setColor(colorHandleFrame);
		painter.setPen(pen);
		painter.setBrush(colorHandle);

		int w = 20;
		int h = 10;
		QRect rectHandle(virtual_pos, vcenter - h / 2, w, h);
		painter.drawRoundedRect(rectHandle, 4, 4);
		pen.setColor(QColor(255, 100, 100));
		painter.setPen(pen);
		painter.drawLine(QPoint(virtual_pos, vcenter + 10), QPoint(virtual_pos, vcenter - 10));
	}

}

int MySlider::PosToProg(int position)
{
	int width = this->width() - 20;
	int xoff = 10;
	position -= xoff;
	if (position < 0)
	{
		position = 0;
	}
	else if (position > width)
	{
		position = width;
	}
	return position * m_range / width;
}

int MySlider::ProgToPos(int progress)
{
	int width = this->width() - 20;
	int xoff = 10;
	return xoff + width * progress / m_range;
}
