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
#include <QImage>

class _object3D:public _basic_object3D
{
 public:
  vector<_vertex3f> Vertices_normals;
  vector<_vertex2f> Vertices_texture_coordinates;

  vector<_vertex3ui> Triangles;
  vector<_vertex3f> Triangles_normals;


  void draw_line();
  void draw_fill();
  void draw_chess();
  void draw_illumination_flat_shading();
  void draw_illumination_smooth_shading();
  void draw_texture();
  void draw_texture_illumination_flat_shading();
  void draw_texture_illumination_smooth_shading();

  void compute_triangles_normals();
  void compute_vertices_normals();

protected:
  vector<int> num_normales;
  vector<_vertex2f> tex_coords;
};

#endif // OBJECT3D_H
