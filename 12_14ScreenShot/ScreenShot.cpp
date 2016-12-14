#include <QTimer>
#include <cassert>
#include <QApplication>
#include <QDialog>
#include <QPixmap>
#include <Qfiledialog>
#include <QDesktopWidget>
#include "ScreenShot.h"
//#include 

ScreenShot::ScreenShot(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	assert(
		connect(ui.actionCapture, SIGNAL(clicked()), this, SLOT(onCapture()))
		);
	assert(
		connect(ui.actionSave, SIGNAL(clicked()), this, SLOT(onSave()))
		);
}

int ScreenShot::onCapture()
{
	// 令本窗口隐藏
	this->hide();

	// 隐藏本窗口需要一定时间，故延时一段时间后才开始截图
	QTimer::singleShot(300, this, SLOT(onDelayedCapture()));

	return 0;
}

int ScreenShot::onDelayedCapture()
{
	QPixmap screen = QPixmap::grabWindow(QApplication::desktop()->winId());
	RegionSelector dlg(screen, this);
	if (QDialog::Accepted == dlg.exec())
	{
		QPixmap region = screen.copy(dlg.selectRegion);
		ui.frame->display(region);
	}
	this->showNormal();
	return 0;
}

int ScreenShot::onSave()
{	
	QPixmap picture = ui.frame->pixmap();
	
	//保存到目标文件
	QString filename = QFileDialog::getSaveFileName(this, "Save Picture", "", "Image File(*.jpg)");
	if (filename.length() > 0)
	{
		picture.save(filename);
	}

	return 0;
}
