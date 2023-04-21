#include "search.h"

Search::Search()
{

}

void Search::addNewWords(QString word, int count)
{
    QRegularExpression rx("\\s+");
    QStringList wordsList = word.split(rx, Qt::SkipEmptyParts);

    Request temp;

    if (count < 10)
    {
        temp.name = "request00" + QString::number(count);
    }
    else if (count >= 10 && count < 100)
    {
        temp.name = "request0" + QString::number(count);
    }
    else if (count >= 100)
    {
        temp.name = "request" + QString::number(count);
    }

    foreach(QString word, wordsList)
    {
        if (!temp.words.contains(word))
        {
            temp.words.append(word);
        }
    }
    req.push_back(temp);
}

void Search::addAnswer()
{


    /*
    QVector<QString>::Iterator vecStr;
    for(vecStr = words.begin(); vecStr != words.end(); vecStr++)
    {
        QRegularExpression rx("\\s+");
        QStringList wordsList = vecStr->split(rx, Qt::SkipEmptyParts);

        foreach(QString word, words)
        {
            if(answer.contains(word))
            {

            }
            else
            {
                Answer ans;

            }
        }



    }
    */

}

void Search::showAnswer()
{
    /*
    QMap<QString, Answer>::Iterator it;
    for(it = answer.begin(); it != answer.end(); it++)
    {
        QString out;
        out = "index[\"" + it.key() + "\"]=";
        Answer answ = it.value();
        for(int i = 0; i < answ.size(); i++)
        {
            out += "{" + QString::number(answ.getDocId(i)) + "}";
            if (i != answ.size() - 1)
            {
                out += ", ";
            }
        }
        out += ";";
        qDebug() << out;
    }
    */
}

QStringList Search::getWords(int count)
{
    return req[count].words;
}

/*

  запихнули слова в вектор сток
  далее вектор строк парсим на слова в requestn
  далее wouestn сравнваем с freqDict
    если слово есть, то result = true,


*/

