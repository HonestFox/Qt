/********************************************************************************
** Form generated from reading UI file 'ScreenShot.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCREENSHOT_H
#define UI_SCREENSHOT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "AfPicture.h"

QT_BEGIN_NAMESPACE

class Ui_ScreenShotClass
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QToolButton *actionCapture;
    QToolButton *actionSave;
    QSpacerItem *verticalSpacer;
    AfPicture *frame;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ScreenShotClass)
    {
        if (ScreenShotClass->objectName().isEmpty())
            ScreenShotClass->setObjectName(QStringLiteral("ScreenShotClass"));
        ScreenShotClass->resize(927, 575);
        centralWidget = new QWidget(ScreenShotClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        actionCapture = new QToolButton(centralWidget);
        actionCapture->setObjectName(QStringLiteral("actionCapture"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/ScreenShot/Resources/Shot.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCapture->setIcon(icon);
        actionCapture->setIconSize(QSize(128, 128));
        actionCapture->setAutoRaise(true);

        verticalLayout->addWidget(actionCapture);

        actionSave = new QToolButton(centralWidget);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/ScreenShot/Resources/Save.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave->setIcon(icon1);
        actionSave->setIconSize(QSize(128, 128));
        actionSave->setAutoRaise(true);

        verticalLayout->addWidget(actionSave);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout);

        frame = new AfPicture(centralWidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(2);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);

        horizontalLayout->addWidget(frame);

        ScreenShotClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ScreenShotClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 927, 23));
        ScreenShotClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ScreenShotClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        ScreenShotClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(ScreenShotClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        ScreenShotClass->setStatusBar(statusBar);

        retranslateUi(ScreenShotClass);

        QMetaObject::connectSlotsByName(ScreenShotClass);
    } // setupUi

    void retranslateUi(QMainWindow *ScreenShotClass)
    {
        ScreenShotClass->setWindowTitle(QApplication::translate("ScreenShotClass", "ScreenShot", 0));
        actionCapture->setText(QApplication::translate("ScreenShotClass", "...", 0));
        actionSave->setText(QApplication::translate("ScreenShotClass", "...", 0));
    } // retranslateUi

};

namespace Ui {
    class ScreenShotClass: public Ui_ScreenShotClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCREENSHOT_H
