#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Test11_8a_12_13.h"

class Test11_8a_12_13 : public QMainWindow
{
    Q_OBJECT

public:
    Test11_8a_12_13(QWidget *parent = Q_NULLPTR);
	//QString GetPeriod();
	//QString GetGrain();
	//QString GetRadius();
private slots:
	int OnSettingsChanged();

private:
    Ui::Test11_8a_12_13Class ui;
};
