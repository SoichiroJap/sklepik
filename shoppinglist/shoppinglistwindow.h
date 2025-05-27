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
};

#endif // SHOPPINGLISTWINDOW_H
