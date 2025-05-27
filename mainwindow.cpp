#include "mainwindow.h"
#include "shoppinglistwindow.h"
#include "storewindow.h"
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
    if (!shoppingWindow)
        shoppingWindow = new ShoppingListWindow(this);
    shoppingWindow->show();
    shoppingWindow->raise();
    shoppingWindow->activateWindow();
}

void MainWindow::handleStoreClicked()
{
    if (!storeWindow)
        storeWindow = new StoreWindow(this);
    storeWindow->show();
    storeWindow->raise();
    storeWindow->activateWindow();
}
