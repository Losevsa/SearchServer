#include "searchserver.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SearchServer w;
    w.show();
    return a.exec();
}
