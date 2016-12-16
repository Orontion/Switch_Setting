#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:


    void on_but_Add_clicked();

    void on_table_VLAN_itemSelectionChanged();

    void on_but_Delete_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
