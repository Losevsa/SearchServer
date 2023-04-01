#include "docsindexing.h"

DocsIndexing::DocsIndexing()
{
}

void DocsIndexing::addDocs(QVector<QString> docs)
{
    this->docs = docs;
}

void DocsIndexing::addNewDoc(QString doc)
{
    docs.push_back(doc);
}

void DocsIndexing::addFreq()
{
    writeIntoFreq.lock();



    writeIntoFreq.unlock();
}
