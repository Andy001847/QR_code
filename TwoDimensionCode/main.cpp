#include "TwoDimensionCode.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TwoDimensionCode w;
    w.show();

    return a.exec();
}
