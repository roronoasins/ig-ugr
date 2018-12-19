/*
* Practicas de IG
* Domingo Martin Perandres© 2014-2018
* dmartin@ugr.es
*
* GPL 3
*/

#include <QApplication>
#include <QMainWindow>
#include <QSurfaceFormat>
#include "window.h"

int main( int argc, char ** argv )
{
  QApplication Application( argc, argv );

  QSurfaceFormat Format;
  Format.setDepthBufferSize(24);
  Format.setStencilBufferSize(8);
  QSurfaceFormat::setDefaultFormat(Format);

  _window Window;
  Window.show();
  return Application.exec();
}
