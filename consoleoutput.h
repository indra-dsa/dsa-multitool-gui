#ifndef CONSOLEOUTPUT_H
#define CONSOLEOUTPUT_H

#include <QDialog>

namespace Ui {
class ConsoleOutput;
}

class ConsoleOutput : public QDialog
{
    Q_OBJECT

public:
    explicit ConsoleOutput(QWidget *parent = nullptr);
    ~ConsoleOutput();

private:
    Ui::ConsoleOutput *ui;
};

#endif // CONSOLEOUTPUT_H
