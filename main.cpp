#include <QApplication>
#include "dsamainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    a.setOrganizationName("Double Shot Audio");
    a.setOrganizationDomain("doubleshotaudio.com");
    a.setApplicationName("Multitool");

    DSAMainWindow w;
    w.show();
    return a.exec();
}
