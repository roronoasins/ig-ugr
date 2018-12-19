/*
* Prácticas de IG
* Copyright Domingo Martín Perandrés 2014-218
* dmartin@ugr.es
*
* GPL 3
*/

#ifndef AXIS_H
#define AXIS_H

#include "basic_object3d.h"

namespace _axis_ne {

  const float DEFAULT_AXIS_SIZE=5000;
}

class _axis:public _basic_object3D
{
public:
  _axis(float Size=_axis_ne::DEFAULT_AXIS_SIZE);

  void draw_line();
};

#endif
