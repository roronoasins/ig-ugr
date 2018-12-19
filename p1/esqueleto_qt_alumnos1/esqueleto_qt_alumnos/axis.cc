/*
* Practicas de IG
* Domingo Martin Perandres© 2014-2018
* dmartin@ugr.es
*
* GPL 3
*/

#include "axis.h"

using namespace _colors_ne;

/**
*
*@param
*@returns
*/

_axis::_axis(float Size)
{
  Vertices.resize(5);

  Vertices[0]=_vertex3f(-Size,0,0);
  Vertices[1]=_vertex3f(Size,0,0);

  Vertices[2]=_vertex3f(0,-Size,0);
  Vertices[3]=_vertex3f(0,Size,0);

  Vertices[4]=_vertex3f(0,0,-Size);
  Vertices[5]=_vertex3f(0,0,Size);
}


/**
* Funcion que dibuja los ejes utilizando la primitiva grafica de lineas
*
*@param
*@returns
*/

void _axis::draw_line()
{
  glLineWidth(1);
  glBegin(GL_LINES);
  // eje X, color rojo
  glColor3fv((GLfloat *) &RED);
  glVertex3fv((GLfloat *) &Vertices[0]);
  glVertex3fv((GLfloat *) &Vertices[1]);
  // eje Y, color verde
  glColor3fv((GLfloat *) &GREEN);
  glVertex3fv((GLfloat *) &Vertices[2]);
  glVertex3fv((GLfloat *) &Vertices[3]);
  // eje Z, color azul
  glColor3fv((GLfloat *) &BLUE);
  glVertex3fv((GLfloat *) &Vertices[4]);
  glVertex3fv((GLfloat *) &Vertices[5]);
  glEnd();
}


