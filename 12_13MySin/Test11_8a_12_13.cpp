#include <QSpinBox>
#include <cassert>
#include "Test11_8a_12_13.h"

Test11_8a_12_13::Test11_8a_12_13(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	assert(
		connect(
			ui.spinBoxGrain,
			SIGNAL(valueChanged(int)),
			this,
			SLOT(OnSettingsChanged())
			)
		);

	assert(
		connect(
			ui.spinBoxPeriod,
			SIGNAL(valueChanged(int)),
			this,
			SLOT(OnSettingsChanged())
			)
		);

	assert(
		connect(
			ui.spinBoxRadius,
			SIGNAL(valueChanged(int)),
			this,
			SLOT(OnSettingsChanged())
			)
		);
}

int Test11_8a_12_13::OnSettingsChanged()
{
	int Period = ui.spinBoxPeriod->value();
	int Grain = ui.spinBoxGrain->value();
	int Radius = ui.spinBoxRadius->value();

	ui.frame->Adjust(Period, Grain, Radius);
	return 0;

}

//QString Test11_8a_12_13::GetPeriod()
//{
//	return ui.spinBoxPeriod->text();
//}
//
//QString Test11_8a_12_13::GetGrain()
//{
//	return ui.spinBoxGrain->text();
//}
//
//QString Test11_8a_12_13::GetRadius()
//{
//	return ui.spinBoxRadius->text();
//}
