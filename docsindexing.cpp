#include "docsindexing.h"

void addNewFreq(int docId, QMap<QString, QVector<Entry>> *freqDictionary, QMutex* mutex, QString doc)
{
    Entry test;
    test.count = 2;
    test.docId = 3;
    QVector<Entry> testTwo;
    testTwo.push_back(test);

    QMap<QString, QVector<Entry>> temp;

    QMutexLocker locker(mutex);
    freqDictionary->insert("asdf", testTwo);

}

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

void DocsIndexing::addFreqThreaded()
{
    QVector<QFuture<void>> threads;
    threads.reserve(5);

    Entry test;
    test.count = 1;
    test.docId = 2;
    QVector<Entry> testTwo;
    testTwo.push_back(test);
    freqDictionary.insert("qwer", testTwo);

    int threadsCount = 0;
    for (int i = 0; i < docs.size(); i++)
    {

        threads.append(QtConcurrent::run(addNewFreq, i, &freqDictionary, &writeIntoFreq, docs[i]));
        threadsCount++;

        for (auto& future : threads) {
            future.waitForFinished();
        }

        if (threadsCount == 5)
        {
            for (auto& future : threads) {
                future.waitForFinished();
            }

            threadsCount = 0;
            threads.clear();
        }
    }


    QList<QString> anotherkeys = freqDictionary.keys();

    for (const QString& key : anotherkeys) {
        qDebug() << key;
    }
}




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


}
  */

