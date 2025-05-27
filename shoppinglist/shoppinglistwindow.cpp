#include "shoppinglistwindow.h"
#include "ui_shoppinglistwindow.h"

ShoppingListWindow::ShoppingListWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ShoppingListWindow)
{
    ui->setupUi(this);
    setWindowTitle("Lista zakupów");
}

ShoppingListWindow::~ShoppingListWindow()
{
    delete ui;
}
