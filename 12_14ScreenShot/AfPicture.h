#ifndef AFPICTURE_H
#define AFPICTURE_H

#include <QFrame>

/* AfPicture
	按比例显示图像

	作者：邵发
	版本: 2016-03-14
	官网: http://afanihao.cn 
	本代码为 C/C++学习指南(实战篇) 官方示例代码，最新版本请到官网下载

*/

class AfPicture : public QFrame
{
	Q_OBJECT

public:
	AfPicture(QWidget *parent);
	~AfPicture();

	// 若imageFile为NULL，则表示不显示图片
	void display(const QString& imageFile);
	void display(const QPixmap& pixmap);

	const QPixmap& pixmap()
	{
		return m_picture;
	}

private:
	void paintEvent ( QPaintEvent * event );

private:
	QPixmap m_picture;
};

#endif // AFPICTURE_H
