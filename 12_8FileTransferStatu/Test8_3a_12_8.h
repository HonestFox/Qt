#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Test8_3a_12_8.h"

class Test8_3a_12_8 : public QMainWindow
{
    Q_OBJECT

public:
    Test8_3a_12_8(QWidget *parent = Q_NULLPTR);

private:
    Ui::Test8_3a_12_8Class ui;

private slots:
	int OnBtnBrowse();
	int OnBtnTransfer();
};
