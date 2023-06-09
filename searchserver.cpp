#include "searchserver.h"
#include "ui_searchserver.h"

SearchServer::SearchServer(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SearchServer)
{
    ui->setupUi(this);
    if (!loadConfig())
    {
        ui->centralwidget->hide();
    }
    else
    {
        //freq_dictionary = new QMap<QString, QVector<Entry>>;
        currentCount = new int(0);
        this->setWindowTitle(config.name);
        loadRequests();
        //для прогресс бара
        //QtConcurrent::run(docsIndexing,config.doscCount, currentCount);
        //*currentCount = *currentCount + 1 ;
        //qDebug() << *currentCount;
    }
}

SearchServer::~SearchServer()
{
    delete ui;
}

bool SearchServer::loadConfig()
{
    QFile configFile("config.json");
    if(!configFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        ui->statusbar->showMessage("Can't open config.json");
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

    readFiles();
    //checkFreq();
    config.doscCount = config.filesPath.size();

    return true;
}

void SearchServer::loadRequests()
{
    QFile configFile("requests.json");
    if(!configFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        ui->statusbar->showMessage("Can't open requests.json");
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
    int count = 1;
    foreach (const QJsonValue& value, files)
    {
        //QVector<QString> temp;
        //temp.push_back(value.toString());
        searchWords.addNewWords(value.toString(), count);
        count++;
        //config.filesPath.push_back(value.toString());
                //value.toString();
    }

}

void SearchServer::readFiles()
{
    for (int i = 0; i < config.filesPath.size(); i++)
    {
        QFile file(config.filesPath[i]);
        if(!file.open(QFile::ReadOnly | QFile::Text))
        {
            continue;
        }
        QString str = file.readAll();
        indexing.addNewDoc(str);
        //docs.push_back(str);
    }

    indexing.addFreqThreaded();
    indexing.showFreq(ui->freqDict);
    //indexing.addDocs(docs);
}

void SearchServer::loadRequestIntoAnswer()
{

}










