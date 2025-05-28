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

    connect(ui->checkBoxDarkMode, &QCheckBox::stateChanged,
            this, &MainWindow::on_checkBoxDarkMode_stateChanged);
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

void MainWindow::on_checkBoxDarkMode_stateChanged(int state)
{
    if (state == Qt::Checked) {
        qApp->setStyleSheet("QWidget { background-color: #2d2d2d; color: #ffffff; }"
                            "QLineEdit, QSpinBox, QDoubleSpinBox, QListWidget, QPushButton { background-color: #444; color: #fff; }"
                            "QPushButton:hover { background-color: #666; }");
    } else {
        qApp->setStyleSheet("");
    }
}
