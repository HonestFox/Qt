#pragma once

#include <QFrame>
#include <QPaintEvent>
#include <QString>
#include <QPainter>

class MyOverlay : public QFrame
{
	Q_OBJECT

public:
	MyOverlay(QWidget *parent);
	~MyOverlay();

	void setText(const QString& text);

private:
	virtual void paintEvent(QPaintEvent * event);

private:
	QString m_text;
};
