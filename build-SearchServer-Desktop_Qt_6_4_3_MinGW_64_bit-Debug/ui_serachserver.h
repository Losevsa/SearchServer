/********************************************************************************
** Form generated from reading UI file 'serachserver.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERACHSERVER_H
#define UI_SERACHSERVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SerachServer
{
public:
    QWidget *centralwidget;
    QLineEdit *requestURL;
    QPushButton *openRequest;
    QTextBrowser *requests;
    QProgressBar *progressBarIndexation;
    QLabel *progressLabel;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *SerachServer)
    {
        if (SerachServer->objectName().isEmpty())
            SerachServer->setObjectName("SerachServer");
        SerachServer->resize(707, 472);
        centralwidget = new QWidget(SerachServer);
        centralwidget->setObjectName("centralwidget");
        requestURL = new QLineEdit(centralwidget);
        requestURL->setObjectName("requestURL");
        requestURL->setGeometry(QRect(10, 20, 221, 22));
        requestURL->setReadOnly(true);
        openRequest = new QPushButton(centralwidget);
        openRequest->setObjectName("openRequest");
        openRequest->setGeometry(QRect(240, 20, 75, 24));
        requests = new QTextBrowser(centralwidget);
        requests->setObjectName("requests");
        requests->setGeometry(QRect(10, 50, 351, 71));
        progressBarIndexation = new QProgressBar(centralwidget);
        progressBarIndexation->setObjectName("progressBarIndexation");
        progressBarIndexation->setGeometry(QRect(150, 130, 118, 23));
        progressBarIndexation->setValue(24);
        progressLabel = new QLabel(centralwidget);
        progressLabel->setObjectName("progressLabel");
        progressLabel->setGeometry(QRect(10, 130, 131, 16));
        SerachServer->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(SerachServer);
        statusbar->setObjectName("statusbar");
        SerachServer->setStatusBar(statusbar);

        retranslateUi(SerachServer);

        QMetaObject::connectSlotsByName(SerachServer);
    } // setupUi

    void retranslateUi(QMainWindow *SerachServer)
    {
        SerachServer->setWindowTitle(QCoreApplication::translate("SerachServer", "SerachServer", nullptr));
        openRequest->setText(QCoreApplication::translate("SerachServer", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214", nullptr));
        progressLabel->setText(QCoreApplication::translate("SerachServer", "\320\237\321\200\320\276\320\263\321\200\320\265\321\201\321\201 \320\270\320\275\320\264\320\265\320\272\321\201\320\260\321\206\320\270\320\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SerachServer: public Ui_SerachServer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERACHSERVER_H
