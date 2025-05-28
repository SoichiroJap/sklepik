#ifndef STOREWINDOW_H
#define STOREWINDOW_H

#include <QMainWindow>

namespace Ui {
class StoreWindow;
}

class StoreWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit StoreWindow(QWidget *parent = nullptr);
    ~StoreWindow();

private:
    Ui::StoreWindow *ui;

private slots:
    void on_pushButtonAddToCart_clicked();
    void handleZaplac(const QStringList& produkty, double suma);
};

#endif // STOREWINDOW_H
