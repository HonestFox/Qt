#include <cassert>
#include "Test11_9a_12_13.h"

Test11_9a_12_13::Test11_9a_12_13(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	//初始化提示框
	m_tooltip = new MyOverlay(this);
	m_tooltip->setFixedSize(40, 20);
	m_tooltip->hide();

	assert(
		connect(
			ui.m_seekBar,
			SIGNAL(focused(bool)),
			this,
			SLOT(onSeekFocused(bool))
			)
		);
	assert(
		connect(
			ui.m_seekBar,
			SIGNAL(clicked(int)),
			this,
			SLOT(onSeekClicked(int))
			)
		);
 	assert(
 		connect(
 			ui.m_seekBar,
 			SIGNAL(tracking(int , QPoint)),
 			this,
 			SLOT(onSeekTracking(int, QPoint))
 			)
 		);
}

int Test11_9a_12_13::onSeekFocused(bool yes)
{
	//拖动条高亮时，显示提示窗
	m_tooltip->setVisible(yes);
	return 0;
}

int Test11_9a_12_13::onSeekClicked(int progress)
{
	return 0;
}

int Test11_9a_12_13::onSeekTracking(int progress, QPoint pos)
{
	//显示位置信息
	char buf[64];
	sprintf(buf, "%d", progress);
	m_tooltip->setText(buf);

	pos.setY(-25);
	pos.setX(pos.x() - 30);
	pos = ui.m_seekBar->mapToGlobal(pos);
	m_tooltip->move(pos);
	return 0;
}
