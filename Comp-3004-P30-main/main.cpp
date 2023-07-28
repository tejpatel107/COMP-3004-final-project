#include <QApplication>
#include "mainwindow.h"
#include"cpu.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Cpu cpu;


    cpu.startDevice();

    return a.exec();
}
