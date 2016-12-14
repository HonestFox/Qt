#include "MyOverlay.h"

MyOverlay::MyOverlay(QWidget *parent)
	: QFrame(parent)
{
	setWindowFlags(Qt::ToolTip);
	setAttribute(Qt::WA_TranslucentBackground);
}

MyOverlay::~MyOverlay()
{
}

void MyOverlay::setText(const QString& text)
{
	m_text = text;
	update();
}

void MyOverlay::paintEvent(QPaintEvent * event)
{
	QPainter painter(this);
	QPen pen;
	painter.setRenderHint(QPainter::Antialiasing);		//抗锯齿

	QColor colorHandle = QColor(0xff, 0xff, 0xff, 240);
	QColor colorHandleFrame = QColor(0xCCCCCC);

	pen.setWidth(4);
	pen.setColor(colorHandle);
	painter.setPen(colorHandle);
	painter.setBrush(colorHandle);

	int w = width();
	int h = height();

	QRect rectHandle(QPoint(0, 0), QPoint(w+10, h));
	painter.drawRect(rectHandle);

	//显示文本：所选区域的大小
	QFont font = painter.font();
	font.setPixelSize(20);
	painter.setFont(font);

	painter.setPen(QPen(QColor(44, 143, 214)));
	QRect textRect(0, 0, w, h);
	painter.drawText(textRect, Qt::AlignAbsolute, " "+m_text);
}
