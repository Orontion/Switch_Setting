#ifndef TERMINAL_H
#define TERMINAL_H

#include <QMainWindow>

namespace Ui {
class Terminal;
}

class Terminal : public QMainWindow
{
    Q_OBJECT

public:
    explicit Terminal(QWidget *parent = 0);
    ~Terminal();

private:
    Ui::Terminal *ui;
};

#endif // TERMINAL_H
