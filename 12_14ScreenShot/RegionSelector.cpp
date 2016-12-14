#include "RegionSelector.h"

RegionSelector::RegionSelector(const QPixmap& screen, QWidget *parent)
	: QDialog(parent)
	,m_shutter("shutter.wav")
	,m_image(screen)
{
	// 在paintEvent之前生效
	m_dragging = false;
	setMouseTracking(true);

	setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);
	
	showFullScreen();
}

RegionSelector::~RegionSelector()
{
}


void RegionSelector::paintEvent(QPaintEvent *event)
{
	// 先调用QT框架的画法，如果需要透明叠加要需要调用这个
	QWidget::paintEvent(event);

	int w = width(), h = height();

	// 画背景图片 
	QPainter painter(this);
	QRectF target(0, 0, width(), height());
	QRectF source(0, 0, m_image.width(), m_image.height());
	painter.drawPixmap(target, m_image, source);

	// 画十字线
	int x = m_pos.x(), y = m_pos.y();
	//x -= 1; y -= 1;
	x += 1; y += 1;
	//qDebug("repaint: (%dx%d)", x, y);
	painter.setPen(QColor(0, 255, 0, 150));
	painter.drawLine(0, y, w, y);
	painter.drawLine(x, 0, x, h);
	painter.setPen(QColor(160, 160, 160, 150));
	painter.drawLine(0, y, w, y);
	painter.drawLine(x, 0, x, h);

	if (m_dragging)
	{
		QRect selected(m_start, m_pos);
		// 区域
		painter.setPen(QColor(100, 100, 100));
		painter.drawRect(selected);

		// 显示文本：所选区域的大小
		QRect textRect(0, 0, 50, 16);
		textRect.moveCenter(selected.center());

		// 文本背景
		painter.setBrush(QColor(30, 30, 30));
		painter.drawRect(textRect);

		// 文本
		painter.setPen(QColor(255, 255, 255));
		char text[32];
		sprintf(text, "%dx%d", selected.width(), selected.height());
		painter.drawText(textRect, Qt::AlignCenter, text);
	}
}

void RegionSelector::mouseMoveEvent(QMouseEvent * event)
{
	m_pos = event->pos();
	update();
}

void RegionSelector::mousePressEvent(QMouseEvent * event)
{
	m_dragging = true;
	m_start = event->pos();
}

void RegionSelector::mouseReleaseEvent(QMouseEvent * event)
{
	m_end = event->pos();
	m_dragging = false;
	update();

	// 限定最少选定16x16区域
	if (m_end.x() > m_start.x() + 16 && m_end.y() > m_start.y() + 16)
	{
		m_shutter.play();
		selectRegion = QRect(m_start, m_end);
		accept();
	}
}