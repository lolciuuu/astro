#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <QWidget>
#include <QPainter>
#include <QDebug>
#include <QVector>
#include <QImage>
#include <QPair>

const ushort ENTITY_SIZE( 30 );

class Renderer : public QWidget
{
  Q_OBJECT
public:
  explicit Renderer(QWidget *parent = 0);

  void setCurrentEntity( int No ) { pSelectMode = false; pCurrentEntityNo = No; this->repaint(); }
  void enableSelectMode( bool P ) { pSelectMode = P; }
  bool isSelectedMode() const { return pSelectMode; }
  bool isMustSave() const { return pIsNotSave; }
  void save();
  void load();

protected:
  void paintEvent(QPaintEvent *);
  void mousePressEvent(QMouseEvent *);
  void resizeEvent( QResizeEvent* );
  
signals:
  
public slots:


private:
  void drawGrid( QPainter& painter );
  void drawLevel( QPainter& painter );
  void setEntity( short row, short col );
  void drawSelectedItem( QPainter& painter );

private:
  short pCurrentEntityNo;
  short pLevelH;
  short pLevelW;

  short** pLevel;
  short** pBackground;

  bool isBackground;

  QVector< QImage> pEntitys;


  bool pSelectMode;
  bool pIsNotSave;
  QPair<ushort, ushort> pCurrentPos;

};

#endif // RENDERER_HPP
