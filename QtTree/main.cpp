#include "QtTree.h"
#include "Role.h"
#include <vector>
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    QtTree w;
    w.showMaximized();
    return a.exec();
}
