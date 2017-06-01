#include "confsettings.h"
#include "ui_confsettings.h"

ConfSettings::ConfSettings(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ConfSettings)
{
    ui->setupUi(this);

}

void ConfSettings::Take_Files(QList<QString> FileList){

    QListIterator<QString> i(FileList);

    while (i.hasNext())
        ui->CmbConfFile->addItem(i.next());

};

ConfSettings::~ConfSettings()
{
    delete ui;
}
