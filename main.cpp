#include "dsamainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DSAMainWindow w;
    w.show();
    return a.exec();
}
