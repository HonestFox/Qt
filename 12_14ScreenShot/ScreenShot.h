#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_ScreenShot.h"
#include "RegionSelector.h"

class ScreenShot : public QMainWindow
{
    Q_OBJECT

public:
    ScreenShot(QWidget *parent = Q_NULLPTR);

private slots:
	int onCapture();
	int onSave();
	int onDelayedCapture();

private:
    Ui::ScreenShotClass ui;
};
