#include "consoleoutput.h"
#include "ui_consoleoutput.h"

ConsoleOutput::ConsoleOutput(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConsoleOutput)
{
    ui->setupUi(this);
}

ConsoleOutput::~ConsoleOutput()
{
    delete ui;
}

void ConsoleOutput::printToConsole (QString output)
{
    ui->outputLabel->clear();
    ui->outputLabel->appendPlainText(output);
    ui->outputLabel->ensureCursorVisible();
}
