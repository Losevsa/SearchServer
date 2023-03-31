/********************************************************************************
** Form generated from reading UI file 'searchserver.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCHSERVER_H
#define UI_SEARCHSERVER_H

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

class Ui_SearchServer
{
public:
    QWidget *centralwidget;
    QLineEdit *requestURL;
    QPushButton *openRequest;
    QTextBrowser *requests;
    QProgressBar *progressBarIndexation;
    QLabel *progressLabel;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *SearchServer)
    {
        if (SearchServer->objectName().isEmpty())
            SearchServer->setObjectName("SearchServer");
        SearchServer->resize(707, 472);
        centralwidget = new QWidget(SearchServer);
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
        SearchServer->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(SearchServer);
        statusbar->setObjectName("statusbar");
        SearchServer->setStatusBar(statusbar);

        retranslateUi(SearchServer);

        QMetaObject::connectSlotsByName(SearchServer);
    } // setupUi

    void retranslateUi(QMainWindow *SearchServer)
    {
        SearchServer->setWindowTitle(QCoreApplication::translate("SearchServer", "SerachServer", nullptr));
        openRequest->setText(QCoreApplication::translate("SearchServer", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214", nullptr));
        progressLabel->setText(QCoreApplication::translate("SearchServer", "\320\237\321\200\320\276\320\263\321\200\320\265\321\201\321\201 \320\270\320\275\320\264\320\265\320\272\321\201\320\260\321\206\320\270\320\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SearchServer: public Ui_SearchServer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHSERVER_H
