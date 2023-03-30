#ifndef SERACHSERVER_H
#define SERACHSERVER_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class SerachServer; }
QT_END_NAMESPACE

class SerachServer : public QMainWindow
{
    Q_OBJECT

public:
    SerachServer(QWidget *parent = nullptr);
    ~SerachServer();

private:
    Ui::SerachServer *ui;
};
#endif // SERACHSERVER_H
