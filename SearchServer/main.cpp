#include "serachserver.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SerachServer w;
    w.show();
    return a.exec();
}
