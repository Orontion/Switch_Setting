#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>



namespace Ui {
class MainWindow;
}

class Terminal;
class ConfSettings;
class ConfInterpreter;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    ConfInterpreter *ConfInt;//Указатель на объект - интерпретатор файлов. В Public, пока не придумаю решение получше

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

//Слоты объекта MainWindow
private slots:

//Клик по кнопке "Добавить VLAN"
    void on_but_Add_clicked();
//Действия при изменении выделения содержимого таблицы
    void on_table_VLAN_itemSelectionChanged();
//Клик по кнопке удаления VLAN-а
    void on_but_Delete_clicked();
//Выбор пункта меню "Файл -> Терминал..."
//    void on_action_Term_triggered();

//Область видимости внутри объекта MainWindow
private:
    Ui::MainWindow *ui;
    Terminal *Term;
    ConfSettings *ConfStgs;

};

#endif // MAINWINDOW_H
