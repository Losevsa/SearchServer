#ifndef SEARCHSERVER_H
#define SEARCHSERVER_H

#include <QMainWindow>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>
#include <QFile>
#include <QDebug>
#include <QtConcurrent>
#include <QFuture>
#include <QMap>
#include <regex>
#include <QStringList>
#include <QThread>
#include <QRunnable>
#include <QThreadPool>

#include "docsindexing.h"
#include "search.h"


QT_BEGIN_NAMESPACE
namespace Ui { class SearchServer; }
QT_END_NAMESPACE

struct Configuration
{
    QString name = "SkillboxSearchEngine";
    double version = 0.1;
    int maxResponses = 5;

    QVector<QString> filesPath;
    int doscCount = 0;
};

class SearchServer : public QMainWindow
{
    Q_OBJECT

public:
    SearchServer(QWidget *parent = nullptr);
    ~SearchServer();

    bool loadConfig();  // 1 загружаем конфиг
    void loadRequests();    // 3 загружаем запросы и добавляим их в search
    void readFiles(); // 2 читаем файлы
    void loadRequestIntoAnswer();

private:
    Ui::SearchServer *ui;
    Configuration config;
    QVector<QVector <QString>> words;
    //QVector<QString> docs;
    QMap<QString, QVector<Entry>>* freqDictionary;
    DocsIndexing indexing;
    Search searchWords;
    int *currentCount;

};
#endif // SEARCHSERVER_H
