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

struct Entry
{
    size_t doc_id, count;
};

class SearchServer : public QMainWindow
{
    Q_OBJECT

public:
    SearchServer(QWidget *parent = nullptr);
    ~SearchServer();

    bool loadConfig();
    void loadRequests();
    void readFiles();
    void checkFreq();

private:
    Ui::SearchServer *ui;
    Configuration config;
    QVector<QVector <QString>> words;
    QVector<QString> docs;
    QMap<QString, QVector<Entry>> freq_dictionary;
    int *currentCount;

};
#endif // SEARCHSERVER_H
