#include "serachserver.h"
#include "ui_serachserver.h"

SerachServer::SerachServer(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SerachServer)
{
    ui->setupUi(this);
}

SerachServer::~SerachServer()
{
    delete ui;
}

