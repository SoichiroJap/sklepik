#include "storewindow.h"
#include "ui_storewindow.h"
#include <QMessageBox>
#include <QRegularExpression>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QDateTime>

StoreWindow::StoreWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::StoreWindow)
{
    ui->setupUi(this);

    QStringList produkty = {
        "Ser Cheddar (200g) – 8.50 zł",
        "Jogurt naturalny (1L) – 5.00 zł",
        "Śmietana 18% (300ml) – 3.80 zł",
        "Ser kozi (150g) – 10.00 zł",
        "Mleko bez laktozy 1L – 4.50 zł",
        "Filet z kurczaka (1kg) – 18.00 zł",
        "Mielona wołowina (500g) – 12.00 zł",
        "Kiełbasa śląska (1kg) – 16.00 zł",
        "Boczek wędzony (200g) – 8.00 zł",
        "Indyk piersi (1kg) – 20.00 zł",
        "Jabłka (1kg) – 4.00 zł",
        "Pomarańcze (1kg) – 5.50 zł",
        "Winogrono (1kg) – 7.00 zł",
        "Truskawki (500g) – 6.00 zł",
        "Maliny (150g) – 5.00 zł",
        "Marchew (1kg) – 2.50 zł",
        "Ziemniaki (5kg) – 10.00 zł",
        "Cebula (1kg) – 3.00 zł",
        "Czosnek (100g) – 3.50 zł",
        "Sałata lodowa – 3.00 zł",
        "Bułki kajzerki (6 szt.) – 4.50 zł",
        "Croissant – 3.50 zł",
        "Bagietka francuska – 3.00 zł",
        "Chleb razowy (500g) – 6.00 zł",
        "Bułki grahamki (4 szt.) – 5.00 zł",
        "Tuńczyk w puszce (150g) – 6.00 zł",
        "Fasola czerwona w puszce (400g) – 4.00 zł",
        "Kukurydza konserwowa (340g) – 3.50 zł",
        "Pomidory w puszce (400g) – 5.00 zł",
        "Zupa pomidorowa (400ml) – 6.50 zł",
        "Chipsy solone (150g) – 5.50 zł",
        "Orzechy włoskie (200g) – 10.00 zł",
        "Migdały (200g) – 12.00 zł",
        "Paluszki słone (200g) – 4.00 zł",
        "Popcorn naturalny (100g) – 3.00 zł",
        "Woda gazowana 1.5L – 2.50 zł",
        "Sok jabłkowy 1L – 4.50 zł",
        "Kawa mielona 250g – 12.00 zł",
        "Herbata czarna (50 torebek) – 8.00 zł",
        "Napój energetyczny 250ml – 4.00 zł",
        "Ketchup (500ml) – 6.00 zł",
        "Majonez (400ml) – 7.00 zł",
        "Musztarda (200g) – 4.50 zł",
        "Sos sojowy (250ml) – 8.00 zł",
        "Oliwa z oliwek 500ml – 18.00 zł",
        "Pizza mrożona (450g) – 12.00 zł",
        "Mix warzyw mrożonych (1kg) – 8.00 zł",
        "Frytki mrożone (1kg) – 9.00 zł",
        "Lody waniliowe (1L) – 10.00 zł",
        "Szpinak mrożony (500g) – 6.00 zł",
        "Kasza gryczana (500g) – 5.50 zł",
        "Płatki owsiane (500g) – 4.00 zł",
        "Mąka pszenna (1kg) – 3.50 zł",
        "Makaron pełnoziarnisty (500g) – 6.50 zł",
        "Komosa ryżowa (200g) – 8.00 zł",
        "Sos pomidorowy (500g) – 7.00 zł",
        "Tortille pszenne (6 szt.) – 6.00 zł",
        "Mleko kokosowe (400ml) – 8.00 zł",
        "Ryż basmati (1kg) – 9.00 zł",
        "Cynamon mielony (50g) – 5.00 zł",
        "Miód naturalny (500g) – 15.00 zł",
        "Dżem truskawkowy (300g) – 6.00 zł",
        "Ser feta (200g) – 8.00 zł",
        "Oliwki zielone (200g) – 7.00 zł",
        "Kapary (100g) – 9.00 zł",
        "Jogurt grecki (150g) – 4.50 zł",
        "Maślanka 1L – 3.80 zł",
        "Szynka parmeńska (100g) – 12.00 zł",
        "Kiełbasa krakowska (500g) – 14.00 zł",
        "Gruszki (1kg) – 5.00 zł",
        "Kiwi (1kg) – 8.00 zł",
        "Papryka czerwona (1kg) – 7.00 zł",
        "Cukinia (1kg) – 5.00 zł",
        "Rogal z marmoladą – 3.50 zł",
        "Chleb orkiszowy (500g) – 7.00 zł",
        "Batonik zbożowy – 2.50 zł",
        "Prażynki solone – 3.00 zł",
        "Sok wielowarzywny 1L – 6.00 zł",
        "Herbata zielona (20 torebek) – 7.00 zł",
        "Ocet balsamiczny (250ml) – 15.00 zł",
        "Sos barbecue (300ml) – 9.00 zł",
        "Pierogi ruskie (1kg) – 12.00 zł",
        "Mrożone owoce jagodowe (500g) – 10.00 zł",
        "Kasza jaglana (500g) – 4.50 zł",
        "Otręby pszenne (500g) – 3.50 zł",
        "Hummus (200g) – 6.00 zł",
        "Pesto (190g) – 11.00 zł",
        "Żelatyna (50g) – 3.00 zł",
        "Drożdże świeże (100g) – 2.50 zł",
        "Cukier wanilinowy (50g) – 4.00 zł"
    };


    for (const QString& itemText : produkty) {
        QListWidgetItem* item = new QListWidgetItem(itemText);
        item->setFlags(item->flags() | Qt::ItemIsUserCheckable);
        item->setCheckState(Qt::Unchecked);
        ui->listWidgetStore->addItem(item);
    }

    setWindowTitle("Sklep");
}

StoreWindow::~StoreWindow()
{
    delete ui;
}

void StoreWindow::on_pushButtonAddToCart_clicked()
{
    QStringList wybraneProdukty;
    double suma = 0.0;

    for (int i = 0; i < ui->listWidgetStore->count(); ++i) {
        QListWidgetItem* item = ui->listWidgetStore->item(i);
        if (item->checkState() == Qt::Checked) {
            wybraneProdukty.append(item->text());

            QRegularExpression regex("–\\s*(\\d+\\.?\\d*)\\s*zł");
            QRegularExpressionMatch match = regex.match(item->text());
            if (match.hasMatch()) {
                suma += match.captured(1).toDouble();
            }
        }
    }

    if (wybraneProdukty.isEmpty()) {
        QMessageBox::information(this, "Koszyk pusty", "Nie wybrano żadnych produktów.");
        return;
    }

    QMessageBox msgBox;
    msgBox.setWindowTitle("Koszyk");
    msgBox.setText(QString("Dodano do koszyka.\nŁączna cena: %1 zł").arg(QString::number(suma, 'f', 2)));
    QPushButton* btnZaplac = msgBox.addButton("Zapłać", QMessageBox::AcceptRole);
    QPushButton* btnPowrot = msgBox.addButton("Powrót", QMessageBox::RejectRole);
    msgBox.exec();

    if (msgBox.clickedButton() == btnZaplac) {
        handleZaplac(wybraneProdukty, suma);
    }
}

void StoreWindow::handleZaplac(const QStringList& produkty, double suma)
{
    QString filePath = QFileDialog::getSaveFileName(
        this,
        "Zapisz paragon",
        QDir::homePath() + "/paragon.txt",
        "Pliki tekstowe (*.txt)"
        );

    if (filePath.isEmpty())
        return;

    QFile file(filePath);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream stream(&file);

        stream << "🧾 PARAGON\n\n";
        for (const QString& item : produkty) {
            stream << "- " << item << "\n";
        }

        stream << "\nSuma: " << QString::number(suma, 'f', 2) << " zł\n";
        stream << "Data zakupu: " << QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm") << "\n";

        file.close();
        QMessageBox::information(this, "Paragon zapisany", "Paragon został zapisany pomyślnie.");
    } else {
        QMessageBox::warning(this, "Błąd", "Nie udało się zapisać paragonu.");
    }
}
