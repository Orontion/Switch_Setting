#ifndef CONFSETTINGS_H
#define CONFSETTINGS_H

#include <QMainWindow>

namespace Ui {
class ConfSettings;
}

class ConfSettings : public QMainWindow
{
    Q_OBJECT

public:
    explicit ConfSettings(QWidget *parent = 0);
    ~ConfSettings();

    //Чисто проверить работу формы - общая функция "взять имена файлов"
    void Take_Files(QList<QString> FileList);

private:
    Ui::ConfSettings *ui;
};

#endif // CONFSETTINGS_H
