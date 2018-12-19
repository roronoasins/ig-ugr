/*
* Prácticas de IG 
* Copyright Domingo Martín Perandrés 2014-218
* dmartin@ugr.es
* 
* GPL 3
*/

#ifndef LEVEL2_H
#define LEVEL2_H

#include "tetrahedron.h"

class _level2
{
public:

  void create(float Height1=1, float Width1=0.5);
  void draw_point();
  void draw_line();
  void draw_fill();
  void draw_chess();
  void draw_illumination_flat_shading();
  void draw_illumination_smooth_shading();
  void draw_texture();

protected:
  float Height;
  float Width;

  _tetrahedron Tetrahedron;
};

#endif
