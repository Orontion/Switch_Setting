#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class Terminal;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

//Слоты окна
private slots:

//Клик по кнопке "Добавить VLAN"
    void on_but_Add_clicked();
//Действия при изменении выделения содержимого таблицы
    void on_table_VLAN_itemSelectionChanged();
//Клик по кнопке удаления VLAN-а
    void on_but_Delete_clicked();
//Выбор пункта меню "Файл -> Терминал..."
//    void on_action_Term_triggered();

private:
    Ui::MainWindow *ui;
    Terminal *Term;
};

#endif // MAINWINDOW_H
