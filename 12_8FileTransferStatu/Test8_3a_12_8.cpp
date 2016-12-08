#include <cassert>
#include <QFileDialog>
#include "AfGbk.h"
#include "SendDlg.h"
#include "Test8_3a_12_8.h"

Test8_3a_12_8::Test8_3a_12_8(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	assert(
		connect(
			ui.btnBrowse,
			SIGNAL(clicked()),
			this,
			SLOT(OnBtnBrowse())
			)
		);

	assert(
		connect(
			ui.btnTransfer,
			SIGNAL(clicked()),
			this,
			SLOT(OnBtnTransfer())
			)
		);
}

int Test8_3a_12_8::OnBtnBrowse()
{
	QString FIlePath;
	if (FIlePath.length() <= 0)
	{
		FIlePath = QFileDialog::getOpenFileName(this, AfGbk::ToUnicode("ÇëÑ¡ÔñÎÄ¼þ"));
	}
	ui.lineEdit->setText(FIlePath);
	return 0;
}

int Test8_3a_12_8::OnBtnTransfer()
{
	QString filepath = ui.lineEdit->text();
	SendDlg dlg(filepath, this);
	dlg.exec();
	return 0;
}
