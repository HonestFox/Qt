
#include <QtGui>
#include "AfPicture.h"

#include "AfScaler.h"

AfPicture::AfPicture(QWidget *parent)
	: QFrame(parent)
{
}

AfPicture::~AfPicture()
{
}

void AfPicture::display(const QString& imageFile)
{
	m_picture.load(imageFile);
	update();
}
void AfPicture::display(const QPixmap& pixmap)
{
	m_picture = pixmap;
	update();
}

void AfPicture::paintEvent ( QPaintEvent * event )
{
	// 先让父类画一面
	QPainter painter(this);
	QRect target = this->rect();
	target.adjust(2,2,-2,-2);// 缩小一圈

	painter.setPen(QColor(0x33,0x33, 0x33));
	painter.setBrush(QColor(0xFF, 0xFF, 0xFF));
	painter.drawRect(target);

	target.adjust(2,2,-2,-2);// 缩小一圈
	if(!m_picture.isNull())
	{
		QRect source = m_picture.rect();
		QRect fit = AfScaler::scale(source, target);
		painter.drawPixmap(fit, m_picture, source);
	}
}
