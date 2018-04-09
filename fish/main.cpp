#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Widget wgt;

    wgt.setWindowTitle("Little Gold Fish");
    wgt.show();

    return app.exec();
}
