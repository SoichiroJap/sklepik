#include "storewindow.h"
#include "ui_storewindow.h"

StoreWindow::StoreWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::StoreWindow)
{
    ui->setupUi(this);
    setWindowTitle("Sklep");
}

StoreWindow::~StoreWindow()
{
    delete ui;
}
