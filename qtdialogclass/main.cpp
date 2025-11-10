#include "byterconveter.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    byterconveter w;
    w.setWindowTitle("進制轉換");
    w.show();
    return a.exec();
}
