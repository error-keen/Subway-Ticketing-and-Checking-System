#include "widget.h"
#include <QApplication>
#include "formrengong.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    FormRenGong rg;
    rg.show();
    return a.exec();
}
