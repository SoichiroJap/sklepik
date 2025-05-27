#ifndef SHOPPINGLISTWINDOW_H
#define SHOPPINGLISTWINDOW_H

#include <QMainWindow>

namespace Ui {
class ShoppingListWindow;
}

class ShoppingListWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ShoppingListWindow(QWidget *parent = nullptr);
    ~ShoppingListWindow();

private:
    Ui::ShoppingListWindow *ui;

private slots:
    void on_pushButtonAdd_clicked();
    void on_pushButtonDelete_clicked();
    void on_pushButtonSave_clicked();
    void on_pushButtonLoad_clicked();
    void on_pushButtonStore_clicked();
};

#endif // SHOPPINGLISTWINDOW_H
