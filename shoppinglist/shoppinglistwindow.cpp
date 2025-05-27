#include "shoppinglistwindow.h"
#include "ui_shoppinglistwindow.h"
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

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

void ShoppingListWindow::on_pushButtonSave_clicked()
{
    QString filePath = QFileDialog::getSaveFileName(
        this,
        "Zapisz listę zakupów",
        QDir::homePath(),
        "Pliki tekstowe (*.txt);;Wszystkie pliki (*)"
        );

    if (filePath.isEmpty())
        return;

    QFile file(filePath);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream stream(&file);
        for (int i = 0; i < ui->listWidgetProducts->count(); ++i) {
            stream << ui->listWidgetProducts->item(i)->text() << "\n";
        }
        file.close();
        QMessageBox::information(this, "Zapisano", "Lista została zapisana.");
    } else {
        QMessageBox::warning(this, "Błąd", "Nie udało się zapisać pliku.");
    }
}

