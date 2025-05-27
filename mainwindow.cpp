#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pbShoppingList, &QPushButton::clicked,
            this, &MainWindow::handleShoppingListClicked);

    connect(ui->pbStore, &QPushButton::clicked,
            this, &MainWindow::handleStoreClicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::handleShoppingListClicked()
{
    qDebug() << "Kliknięto: Lista zakupów";
    // otworzyć liste
}

void MainWindow::handleStoreClicked()
{
    qDebug() << "Kliknięto: Sklep";
    //otworzyc sklep
}
