#include "searchserver.h"
#include "ui_searchserver.h"

//функции для qtconcurrent...
/*
void docsIndexing(int num, int *currCount)
{

    for(; *currCount < num;)
    {
        if (*currCount == 1)
        {
            qDebug() << "change";
            break;
        }
        qDebug() << "no";
    }
}

void docsIndexing()
{

}
*/



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
    foreach (const QJsonValue& value, files) {
        QVector<QString> temp;
        temp.push_back(value.toString());
        words.push_back(temp);
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
    //indexing.addDocs(docs);
}

void SearchServer::checkFreq()
{
    //QtConcurrent::run(&indexing, &DocsIndexing::newFreq());

    //QFuture<void> future = QtConcurrent::run(std::ref(indexing), &DocsIndexing::newFreq);

    /*

    for(int i = 0; i < config.filesPath.size(); i++)
    {
        QRegularExpression rx("\\s+");
        QStringList words = docs[i].split(rx, Qt::SkipEmptyParts);

        // Вывести каждое слово на отдельной строке
        Entry entry;
        entry.doc_id = i;
        entry.count = 5;

        QVector<Entry> temp;
        temp.push_back(entry);

        freq_dictionary.insert("test",temp);


        //foreach(QString word, words)
        //{
        for(auto it = freq_dictionary.begin(); it != freq_dictionary.end(); ++it) {
            qDebug() << "Key:" << it.key();

            QVector<Entry> entries = it.value();
            for(int i = 0; i < entries.size(); ++i) {
                Entry entry = entries.at(i);
                qDebug() << "Doc ID:" << entry.doc_id << "Count:" << entry.count;
            }
        }


            //qDebug() << word;
        //}
        //Entry entry;
    }
    */
}










