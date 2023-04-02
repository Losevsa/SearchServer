#ifndef DOCSINDEXING_H
#define DOCSINDEXING_H

#include <QVector>
#include <QString>
#include <QMap>
#include <QMutex>
#include <QRegularExpression>
#include <QtConcurrent>
#include <QThread>
#include <QRunnable>
#include <QThreadPool>

struct Entry
{
    size_t docId, count;
};

class DocsIndexing
{
public:
    DocsIndexing();
    void addDocs(QVector<QString> docs);
    void addNewDoc(QString doc);
    void addFreqThreaded();

public slots:
    void upd()
    {

    }

private:
    QVector<QString> docs;
    QMap<QString, QVector<Entry>>* freqDictionary;
    QMutex writeIntoFreq;
};

#endif // DOCSINDEXING_H
