#include "confinterpreter.h"



ConfInterpreter::ConfInterpreter()
{

}



//Функция сканирования заданной папки в поисках конфигурационных файлов
QList<QString> ConfInterpreter::Scan_Files(QString DirPath){

    QDir WorkDir; //Объект для работы с папкой, содержашей файлы с конфигурациями
    QFileInfoList FileList; //Список файлов, найденных в папке
    QList<QString> Temp; //Временный QList для сохранения результатов поиска

    //Ставим фильтры на осмотр содержимого директории
    WorkDir.setFilter(QDir::Files | QDir::NoSymLinks);

    //Получаем информацию о файлах с заданным фильтром
    FileList = WorkDir.entryInfoList();


    QListIterator<QFileInfo> i(FileList);//Итератор для перегона информации из QFileInfoList в QList

    //Цикл перебора всех значений в FileList
    while (i.hasNext())
        Temp << i.next().fileName();

    return Temp;

};
