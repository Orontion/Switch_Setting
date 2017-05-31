#include "confsettings.h"
#include "ui_confsettings.h"

ConfSettings::ConfSettings(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ConfSettings)
{
    ui->setupUi(this);
}

ConfSettings::~ConfSettings()
{
    delete ui;
}
