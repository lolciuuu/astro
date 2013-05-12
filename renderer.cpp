#include "renderer.hpp"
#include <QMouseEvent>
#include <QMessageBox>
#include <fstream>

bool isInit( true );

Renderer::Renderer(QWidget *parent) :
    QWidget(parent),pCurrentEntityNo( -1 ), pSelectMode( true ), pIsNotSave(false), isBackground( false )
{

    /** HOW TO - dodawanie nowego entity
      - dodanie do resource
      - dodanie do vectora pEntitys
      - dodanie na koniec listy w mainwindow.ui
      */

  pEntitys.push_back( QImage(":img/m1.png") );
  pEntitys.push_back( QImage(":img/m2.png") );
  pEntitys.push_back( QImage(":img/m3.png") );
  pEntitys.push_back( QImage(":img/m4.png") );
  pEntitys.push_back( QImage(":img/m5.png") );
  pEntitys.push_back( QImage(":img/m6.png") );

  pEntitys.push_back( QImage(":img/m7.png") );
  pEntitys.push_back( QImage(":img/m8.png") );
  pEntitys.push_back( QImage(":img/m9.png") );
  pEntitys.push_back( QImage(":img/m10.png") );
  pEntitys.push_back( QImage(":img/m11.png") );
  pEntitys.push_back( QImage(":img/m12.png") );
  pEntitys.push_back( QImage(":img/m13.png") );
  pEntitys.push_back( QImage(":img/m14.png") );
  pEntitys.push_back( QImage(":img/m15.png") );
  pEntitys.push_back( QImage(":img/m16.png") );

  pEntitys.push_back( QImage(":img/m17.png") );
  pEntitys.push_back( QImage(":img/m18.png") );
  pEntitys.push_back( QImage(":img/m19.png") );
  pEntitys.push_back( QImage(":img/m20.png") );
  pEntitys.push_back( QImage(":img/m21.png") );

  pEntitys.push_back( QImage(":img/g.png") );
  pEntitys.push_back( QImage(":img/g1.png") );
  pEntitys.push_back( QImage(":img/g2.png") );
  pEntitys.push_back( QImage(":img/g3.png") );
  pEntitys.push_back( QImage(":img/g4.png") );
  pEntitys.push_back( QImage(":img/g5.png") );
  pEntitys.push_back( QImage(":img/g6.png") );
  pEntitys.push_back( QImage(":img/g7.png") );
  pEntitys.push_back( QImage(":img/g8.png") );
  pEntitys.push_back( QImage(":img/g9.png") );
  pEntitys.push_back( QImage(":img/g10.png") );
  pEntitys.push_back( QImage(":img/g11.png") );
  pEntitys.push_back( QImage(":img/g12.png") );
  pEntitys.push_back( QImage(":img/g13.png") );
  pEntitys.push_back( QImage(":img/g14.png") );
  pEntitys.push_back( QImage(":img/g15.png") );

  pEntitys.push_back( QImage(":img/s1.png") );
  pEntitys.push_back( QImage(":img/s2.png") );

  pEntitys.push_back( QImage(":img/platform1.png") );

  pEntitys.push_back( QImage(":img/skull.png") );

  pEntitys.push_back( QImage(":img/injection.png") );

  qDebug()<<"Elementow:"<<pEntitys.size();

}


/**
 * @brief Renderer::load
 */
void Renderer::load() {

  std::ifstream file;
  file.open("level.lua");

  if( !file.is_open() ) {
      QMessageBox msgBox;
       msgBox.setText("Cannot open file: level.lua");
       msgBox.exec();
    }

  file>>pLevelW;
  file>>pLevelH;

  for ( int i = 0; i< pLevelW; ++i ) {
        for ( int j = 0; j< pLevelH; ++j )
          file>>pLevel[i][j];
    }

  file.close();
  qDebug("Wczytano level");

  {
  std::ifstream file;

  file.open("background.lua");

  file>>pLevelW;
  file>>pLevelH;

  if( file.is_open() ) {
      qDebug("Background is ready");
      for ( int i = 0; i< pLevelW; ++i ) {
            for ( int j = 0; j< pLevelH; ++j )
              file>>pBackground[i][j];
        }
     isBackground = true;
     file.close();

   }

  }
  this->repaint();

}

/** Przy pierwszym resize okreslenie jaki wymiar ma miec macierz na mape.
 * Maksymalne wymiary widgetu zabezpieczaja przed dynamicznym zmienianiem sie wymioarow mapy
 */
void Renderer::resizeEvent( QResizeEvent* ) {

  if ( isInit )
    {
      {
      pLevelH = this->size().width() / ENTITY_SIZE;
      pLevelW = this->size().height() / ENTITY_SIZE;
      isInit = false;

      // Tworzenie tablicy do trzymania calego levelu
      pLevel = new short*[ pLevelW ];
      for ( int i = 0; i< pLevelW; ++i ) {
          pLevel[i] = new short[pLevelH];
      }
      for ( int i = 0; i< pLevelW; ++i ) {
            for ( int j = 0; j< pLevelH; ++j )
              pLevel[i][j] = -1;
      }
    }


      {  pLevelH = this->size().width() / ENTITY_SIZE;
          pLevelW = this->size().height() / ENTITY_SIZE;
          pBackground = new short*[ pLevelW ];
      for ( int i = 0; i< pLevelW; ++i ) {
          pBackground[i] = new short[pLevelH];
      }
      for ( int i = 0; i< pLevelW; ++i ) {
            for ( int j = 0; j< pLevelH; ++j )
              pBackground[i][j] = -1;
      }

      }

      qDebug()<<"Mapa ma wymiary: "<<pLevelW<<"x"<<pLevelH;
   }

}

/**
 * @brief Renderer::paintEvent
 * @param e
 */
void Renderer::paintEvent(QPaintEvent*) {

  QPainter painter( this );
  painter.setRenderHint( QPainter::Antialiasing );
  painter.fillRect( 0,0, this->size().width(), this->size().height(), Qt::black );

  drawGrid( painter );

  if( pSelectMode ) {
      drawSelectedItem( painter );
  }

   drawLevel( painter );



}

/** Rysuje siatke mapy
 * @brief Renderer::drawGrid
 * @param painter
 */
void Renderer::drawGrid( QPainter &painter ) {

  for( int i = 0; i <= this->size().width() / ENTITY_SIZE; i++ )
    painter.drawLine( ENTITY_SIZE * i, 0, ENTITY_SIZE * i , this->size().height() );

  for( int i = 0; i <= this->size().height() / ENTITY_SIZE; i++ )
    painter.drawLine( 0, ENTITY_SIZE * i, this->size().width() , ENTITY_SIZE * i );

}


/**
 * @brief Renderer::mousePressEvent
 * @param e
 */
void Renderer::mousePressEvent(QMouseEvent* e ) {
  qDebug()<<"[EVENT] click";

  int pos_x = e->pos().x();
      pos_x = ( ( pos_x - pos_x%ENTITY_SIZE )/ ENTITY_SIZE );
  int pos_y = e->pos().y();
      pos_y = ( ( pos_y - pos_y%ENTITY_SIZE )/ ENTITY_SIZE );

  if( pSelectMode ) {
      pCurrentPos = qMakePair<ushort, ushort>( pos_x, pos_y );
   }
  else {
      pIsNotSave = true;
      setEntity( pos_x, pos_y );
  }

  this->repaint();

}


/**
 * @brief Renderer::drawLevel
 * @param painter
 */
void Renderer::drawLevel(QPainter &painter) {

    if( isBackground ) {
        for ( int i = 0; i< pLevelH; ++i ) {
             for ( int j = 0; j< pLevelW; ++j ) {
                 if( pBackground[j][i] > -1 ) {
                     painter.drawImage( QRect(i*ENTITY_SIZE,j*ENTITY_SIZE, ENTITY_SIZE, ENTITY_SIZE), pEntitys[ pBackground[j][i] ] );
                   }
               }
          }
    }// background

  for ( int i = 0; i< pLevelH; ++i ) {
       for ( int j = 0; j< pLevelW; ++j ) {
           if( pLevel[j][i] > -1 ) {
               painter.drawImage( QRect(i*ENTITY_SIZE,j*ENTITY_SIZE, ENTITY_SIZE, ENTITY_SIZE), pEntitys[ pLevel[j][i] ] );
             }
         }
    }
}

/**
 * @brief Renderer::setEntity
 * @param row
 * @param col
 */
void Renderer::setEntity(short row, short col) {
  qDebug()<<"Set entity: "<<row<<"x"<<col;

  if( row < pLevelH && col < pLevelW )
    pLevel[col][row] = pCurrentEntityNo;
  else qErrnoWarning("Cegla po za mapa!");

}


void Renderer::drawSelectedItem(QPainter &painter) {

  painter.setPen( Qt::red );
  painter.drawRect( QRect(pCurrentPos.first * ENTITY_SIZE , pCurrentPos.second * ENTITY_SIZE, ENTITY_SIZE, ENTITY_SIZE ) );

}

/**
 * @brief Renderer::save
 */
void Renderer::save() {

  qDebug("Save level to file");

  pIsNotSave = false;
  std::ofstream file;
  file.open("level.lua");

  if( !file.is_open() ) {
      QMessageBox msgBox;
       msgBox.setText("Cannot open file: level.lua");
       msgBox.exec();
    }

  file<<pLevelW<<" "<<pLevelH<<'\n';

  for ( int i = 0; i< pLevelW; ++i ) {
        for ( int j = 0; j< pLevelH; ++j )
          file<<pLevel[i][j]<<" ";
          file<<"\n";
    }

  file.close();
}


