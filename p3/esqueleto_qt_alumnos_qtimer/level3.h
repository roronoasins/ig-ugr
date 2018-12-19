/*
* Prácticas de IG 
* Copyright Domingo Martín Perandrés 2014-218
* dmartin@ugr.es
* 
* GPL 3
*/

#ifndef LEVEL3_H
#define LEVEL3_h

#include "level2.h"

class _level3
{
public:

  void create(float Lenght1=4, float Width1=2);
  void draw_point();
  void draw_line();
  void draw_fill();
  void draw_chess();
  void rot1();
  void rot2();

protected:
  float Lenght;
  float Width;
  float alpha = 0;

  _level2 Level2;
};

#endif
