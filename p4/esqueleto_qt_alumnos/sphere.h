/*
* Prácticas de IG
* Copyright Domingo Martín Perandrés 2014-218
* dmartin@ugr.es
*
* GPL 3
*/

#ifndef SPHERE_H
#define SPHERE_H

#include "object3d_sweep_basic.h"

class _sphere:public _object3d_sweep_basic
{
public:
  void create(unsigned int Divisions, float radio=0.5);
  void compute_vertices_normals();
  void draw_illumination_flat_shading();
  void draw_illumination_smooth_shading();
  void draw_texture();
  float radio;
protected:
    _vertex2f center;

};

#endif
