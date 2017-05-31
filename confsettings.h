#ifndef CONFSETTINGS_H
#define CONFSETTINGS_H

#include <QWidget>

namespace Ui {
class ConfSettings;
}

class ConfSettings : public QWidget
{
    Q_OBJECT

public:
    explicit ConfSettings(QWidget *parent = 0);
    ~ConfSettings();

private:
    Ui::ConfSettings *ui;
};

#endif // CONFSETTINGS_H
