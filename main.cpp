/** MAIN */

#include <QApplication>
#include "mainwindow.hpp"

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  MainWindow w;
  w.move(100,80);
  w.show();
  
  return a.exec();
}
