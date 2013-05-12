#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QScrollArea>
#include <QModelIndex>
#include <QPushButton>
#include <QDebug>

#include "renderer.hpp"

namespace Ui {
  class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT
  
public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();
  
public slots:
  void onErase();
  void onSave();
  void onHand();
  void onPencil();
  void closeEvent(QCloseEvent *e);

private slots:
  void on_listWidget_2_clicked(const QModelIndex &index);


private:
  Ui::MainWindow *ui;
  QAction* pExit;
  QAction* pErase;
  QAction* pSave;
  QAction* pHand;
  QAction* pPencil;

};

#endif // MAINWINDOW_HPP
