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

void ShoppingListWindow::on_pushButtonAdd_clicked()
{
    QString name = ui->lineEditName->text();
    int quantity = ui->spinBoxQuantity->value();
    double price = ui->doubleSpinBoxPrice->value();

    if (name.isEmpty()) return;

    QString itemText = QString("%1   ilość: %2   cena: %3 zł")
                           .arg(name)
                           .arg(quantity)
                           .arg(QString::number(price, 'f', 2));

    QListWidgetItem *item = new QListWidgetItem(itemText);
    item->setFlags(item->flags() | Qt::ItemIsUserCheckable);
    item->setCheckState(Qt::Unchecked);

    ui->listWidgetProducts->addItem(item);
}

void ShoppingListWindow::on_pushButtonDelete_clicked()
{
    for (int i = ui->listWidgetProducts->count() - 1; i >= 0; --i) {
        QListWidgetItem* item = ui->listWidgetProducts->item(i);
        if (item->checkState() == Qt::Checked) {
            delete ui->listWidgetProducts->takeItem(i);
        }
    }
}

