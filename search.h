#ifndef SEARCH_H
#define SEARCH_H

#include <QVector>
#include <QString>
#include <QRegularExpression>
#include <QString>
#include <QStringList>

struct Answer
{
    bool result = false;
    float rank = 0;
    QVector<int> docId;

    void addDocId(int id)
    {
        docId.push_back(id);
    }

    int size()
    {
        return docId.size();
    }

    int getDocId(int n)
    {
        return docId[n];
    }
};

struct Request
{
    QString name;
    QStringList words;
    Answer answer;
};

class Search
{
public:
    Search();

    void addNewWords(QString word, int count);
    void addAnswer();
    void showAnswer();
    QStringList getWords(int count);

private:
    QVector<Request> req;
    //QVector<QString> requests;
    //QMap<QString,Answer> answer;
};

#endif // SEARCH_H
