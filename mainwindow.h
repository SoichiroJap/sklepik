#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "shoppinglist/shoppinglistwindow.h"
#include "store/storewindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void handleShoppingListClicked();
    void handleStoreClicked();
    void on_checkBoxDarkMode_stateChanged(int state);

private:
    Ui::MainWindow *ui;

    ShoppingListWindow* shoppingWindow = nullptr;
    StoreWindow* storeWindow = nullptr;
};

#endif // MAINWINDOW_H
