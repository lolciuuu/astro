#include "mainwindow.hpp"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QApplication>
#include <QDesktopWidget>

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    pSave = new QAction(QIcon(":img/save.png"), tr("&Save"), this);
    connect( pSave, SIGNAL( triggered() ), this, SLOT( onSave() ) );
    ui->mainToolBar->addAction( pSave );

    pHand = new QAction(QIcon(":img/hand.png"), tr("&Select item"), this);
    connect( pHand, SIGNAL( triggered() ), this, SLOT( onHand() ) );
    ui->mainToolBar->addAction( pHand );

    pPencil = new QAction(QIcon(":img/pencil.png"), tr("&Load file"), this);
    connect( pPencil, SIGNAL( triggered() ), this, SLOT( onPencil() ) );
    ui->mainToolBar->addAction( pPencil );

    pErase = new QAction(QIcon(":img/eraser.png"), tr("&Erase"), this);
    connect( pErase, SIGNAL( triggered() ), this, SLOT( onErase() ) );
    ui->mainToolBar->addAction( pErase );

    setStatusTip("Gotowy");

}

MainWindow::~MainWindow()
{
  delete pExit;
  delete ui;
}

/** Wybor z listy cegiel
 * @brief MainWindow::on_listWidget_2_clicked
 * @param index
 */
void MainWindow::on_listWidget_2_clicked( const QModelIndex &index )
{
  qDebug()<<"Selected entity: "<<index.row();
  ui->widget->setCurrentEntity( index.row() );

  setStatusTip("ID:" + QString().setNum( index.row() ) );
    this->repaint();
}


void MainWindow::onErase() {
    qDebug("Erase button pressed");
    ui->widget->setCurrentEntity( -1 );
}


void MainWindow::onSave() {
      qDebug("Save button pressed");
      ui->widget->save();
}

void MainWindow::onHand() {

  if( ui->widget->isSelectedMode() ) {
      ui->widget->enableSelectMode(false );
  }
  else {
       ui->widget->enableSelectMode( true );
    }
}

/** Wczytwanie danych z pliku
 * @brief MainWindow::onPencil
 */
void MainWindow::onPencil() {
     ui->widget->load();
}

/** POkazanie komunikatu z informacja o zapisaniu pliku
 * @brief MainWindow::closeEvent
 */
void MainWindow::closeEvent(QCloseEvent*) {
  if( !ui->widget->isMustSave() ) return;

  QMessageBox msgBox;
  msgBox.setText("The document has been modified.");
  msgBox.setInformativeText("Do you want to save your changes?");
  msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard );
  msgBox.setDefaultButton(QMessageBox::Save);

  msgBox.move(QApplication::desktop()->width()/2 , QApplication::desktop()->height()/2);

  int ret = msgBox.exec();
  switch (ret) {
    case QMessageBox::Save:
         qDebug("Save was clicked");
         ui->widget->save();
        break;
    case QMessageBox::Discard:
        qDebug("Don't Save was clicked");
        break;
    default:
        qDebug("should never be reached");
        break;
  }

  qApp->closeAllWindows();

}


