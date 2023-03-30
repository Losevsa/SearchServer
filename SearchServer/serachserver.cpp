#include "serachserver.h"
#include "ui_serachserver.h"

SerachServer::SerachServer(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SerachServer)
{
    ui->setupUi(this);
    if (!loadConfig())
    {
        ui->centralwidget->hide();
    }

    this->setWindowTitle(config.name);

    loadRequests();

    qDebug() << "qwe";
}

SerachServer::~SerachServer()
{
    delete ui;
}

bool SerachServer::loadConfig()
{
    QFile configFile("config.json");
    if(!configFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        return false;
    }

    QJsonParseError error;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(configFile.readAll(), &error);
    configFile.close();

    if (jsonDoc.isNull()) {
        ui->statusbar->showMessage("Failed to parse JSON:" + error.errorString());
        return false;
    }

    if (!jsonDoc.isObject()) {
        ui->statusbar->showMessage("JSON is not an object");
        return false;
    }

    // Получаем объект конфигурации
    QJsonObject configJson = jsonDoc.object().value("config").toObject();
    QString name = configJson.value("name").toString();
    QString version = configJson.value("version").toString();

    if (version.toDouble() != config.version)
    {
        ui->statusbar->showMessage("Incorect config version");
        return false;
    }

    int maxResponses = configJson.value("max_responses").toInt();

    qDebug() << name << " " << version << " " << maxResponses;

    // Получаем массив файлов
    QJsonArray files = jsonDoc.object().value("files").toArray();
    foreach (const QJsonValue& value, files) {
        config.filesPath.push_back(value.toString());
                //value.toString();
    }

    return true;
}

void SerachServer::loadRequests()
{
    QFile configFile("requests.json");
    if(!configFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        return;
    }

    QJsonParseError error;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(configFile.readAll(), &error);
    configFile.close();

    if (jsonDoc.isNull()) {
        ui->statusbar->showMessage("Failed to parse JSON:" + error.errorString());
        return;
    }

    if (!jsonDoc.isObject()) {
        ui->statusbar->showMessage("JSON is not an object");
        return;
    }

    // Получаем объект конфигурации
    //QJsonObject configJson = jsonDoc.object().value("requests").toObject();
    // Получаем массив файлов
    QJsonArray files = jsonDoc.object().value("requests").toArray();
    foreach (const QJsonValue& value, files) {
        QVector<QString> temp;
        temp.push_back(value.toString());
        words.push_back(temp);
        //config.filesPath.push_back(value.toString());
                //value.toString();
    }
}

