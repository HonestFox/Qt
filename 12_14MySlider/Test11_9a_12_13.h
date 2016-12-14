#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Test11_9a_12_13.h"
#include "MyOverlay.h"
#include "MySlider.h"

class Test11_9a_12_13 : public QMainWindow
{
    Q_OBJECT

public:
    Test11_9a_12_13(QWidget *parent = Q_NULLPTR);

private:
    Ui::Test11_9a_12_13Class ui;
	MyOverlay* m_tooltip;

private slots:
	int onSeekFocused(bool yes);
	int onSeekClicked(int progress);
	int onSeekTracking(int progress, QPoint pos);
};
