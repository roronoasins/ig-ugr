/*
* Prácticas de IG
* Copyright Domingo Martín Perandrés 2014-218
* dmartin@ugr.es
*
* GPL 3
*/

#ifndef OBJECT3D_H
#define OBJECT3D_H

#include "basic_object3d.h"

class _object3D:public _basic_object3D
{
  public:
  vector<_vertex3ui> Triangles;

  void draw_line();
  void draw_fill();
  void draw_chess();

};

#endif // OBJECT3D_H
