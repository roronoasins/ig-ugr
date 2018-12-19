/*
* Prácticas de IG 
* Copyright Domingo Martín Perandrés 2014-218
* dmartin@ugr.es
* 
* GPL 3
*/

#ifndef LEVEL3_H
#define LEVEL3_H

#include "level2.h"

class _level3
{
public:

  void create(float Lenght1=4, float Width1=2);
  void draw_point();
  void draw_line();
  void draw_fill();
  void draw_chess();
  void draw_illumination_flat_shading();
  void draw_illumination_smooth_shading();
  void draw_texture();

protected:
  float Lenght;
  float Width;

  _level2 Level2;
};

#endif
