#ifndef CONFINTERPRETER_H
#define CONFINTERPRETER_H

//Используемые заголовочные файлы
#include <QDir>
#include <QList>
#include <QString>

//Класс интерпретатора конфигурационных файлов
class ConfInterpreter
{

public:
    ConfInterpreter();

    //Функция сканирования заданной папки в поисках конфигурационных файлов
    QList<QString> Scan_Files(QString DirPath);

private:
    QString ChosenFile; //Выбранный файл для работы интерпретатора


};

#endif // CONFINTERPRETER_H
