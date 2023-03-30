#ifndef SERACHSERVER_H
#define SERACHSERVER_H

#include <QMainWindow>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>
#include <QFile>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class SerachServer; }
QT_END_NAMESPACE

struct Configuration
{
    QString name = "SkillboxSearchEngine";
    double version = 0.1;
    int maxResponses = 5;

    QVector<QString> filesPath;
};


class SerachServer : public QMainWindow
{
    Q_OBJECT

public:
    SerachServer(QWidget *parent = nullptr);
    ~SerachServer();

    bool loadConfig();
    void loadRequests();

private:
    Ui::SerachServer *ui;
    Configuration config;
    QVector<QVector <QString>> words;

};
#endif // SERACHSERVER_H
