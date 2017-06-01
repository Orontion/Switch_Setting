#include "mainwindow.h"
#include "ui_mainwindow.h"


//Мой include
#include <QFile>
#include <QMessageBox>
#include <QTextStream>

//Для того, чтобы из этой формы можно было открыть другие, их заголовочные файлы нужно подключать сюда
#include "terminal.h"
#include "confsettings.h"

//Мои модули
#include "confinterpreter.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //Создаем объекты с окнами
    Term = new Terminal(this);
    ConfStgs = new ConfSettings(this);

    //Соединяем сигнал от пункта меню "Терминал..." со слотом "Показать окно" объекта Term
    connect(ui->action_Term, &QAction::triggered, Term, &Terminal::show);
    //Соединяем сигнал от пункта меню "Настройка конфигурирования..." со слотом объекта ConfStgs
    connect(ui->action_ConfSettings, &QAction::triggered, ConfStgs, &ConfSettings::show);

    //Создаём объект интерпретатора файлов
    ConfInt = new ConfInterpreter;
    ConfStgs->Take_Files(ConfInt->Scan_Files(""));
}

MainWindow::~MainWindow()
{
    delete ui;
}class ConfInterpreter;

//Кнопка добавления данных для настройки VLAN
void MainWindow::on_but_Add_clicked()
{
    //Проверка введенных данных
    if (ui->line_txt_VLAN->text().isEmpty())
    {
        QMessageBox::warning(0,"Ошибка","Не введен номер VLAN");
        return;
    }

    //Добавление строки в конец таблицы
    ui->table_VLAN->insertRow(ui->table_VLAN->rowCount());

    //Создаем в новом ряду объект Item, сразу вводим текст с VLAN-ом
    ui->table_VLAN->setItem(ui->table_VLAN->rowCount()-1,0,new QTableWidgetItem(ui->line_txt_VLAN->text()));

    //Проверяем необходимость добавления данных о тэгированных портах, иначе - добавляем "Нет"
    if (!(ui->line_txt_TGD->text().isEmpty()))
    {
        ui->table_VLAN->setItem(ui->table_VLAN->rowCount()-1,1,new QTableWidgetItem(ui->line_txt_TGD->text()));
    }
    else
    {
        ui->table_VLAN->setItem(ui->table_VLAN->rowCount()-1,1,new QTableWidgetItem("Нет"));
    }

    //Проверяем необходимость добавления данных о нетэгированных портах, иначе - добавляем "Нет"
    if (!(ui->line_txt_UTGD->text().isEmpty()))
    {
        ui->table_VLAN->setItem(ui->table_VLAN->rowCount()-1,2,new QTableWidgetItem(ui->line_txt_UTGD->text()));
    }
    else
    {
        ui->table_VLAN->setItem(ui->table_VLAN->rowCount()-1,2,new QTableWidgetItem("Нет"));
    }



    //Очистка полей ввода
    ui->line_txt_VLAN->clear();
    ui->line_txt_TGD->clear();
    ui->line_txt_UTGD->clear();
}

//Проверка наличия выбранных строк в таблице, чтобы включать/выключать кнопку удаления строк
void MainWindow::on_table_VLAN_itemSelectionChanged()
{
    if(ui->table_VLAN->selectionModel()->selectedRows().count() != 0)
    {
        ui->but_Delete->setEnabled(true);
    }
    else
    {
        ui->but_Delete->setEnabled(false);
    }

}


//Клик по кнопке удаления строки из таблицы
void MainWindow::on_but_Delete_clicked()
{
    ui->table_VLAN->removeRow(ui->table_VLAN->selectionModel()->currentIndex().row());
}
