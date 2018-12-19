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
  vector<_vertex3f> Vertices_normals;
  vector<_vertex2f> Vertices_texture_coordinates;

  vector<_vertex3ui> Triangles;
  vector<_vertex3f> Triangles_normals;

  _object3D(){Selected_triangle=-1;};

  void draw_line();
  void draw_fill();
  void draw_selection();

  void selected_triangle(int Selected_triangle1){Selected_triangle=Selected_triangle1;};
  int selected_triangle(){return Selected_triangle;};

protected:
  int Selected_triangle;
};

#endif // OBJECT3D_H
