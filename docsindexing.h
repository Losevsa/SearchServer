#ifndef DOCSINDEXING_H
#define DOCSINDEXING_H

#include <QVector>
#include <QString>
#include <QMap>
#include <QMutex>

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
    void addFreq();

private:
    QVector<QString> docs;
    QMap<QString, QVector<Entry>> freqDictionary;
    QMutex writeIntoFreq;
};

#endif // DOCSINDEXING_H
