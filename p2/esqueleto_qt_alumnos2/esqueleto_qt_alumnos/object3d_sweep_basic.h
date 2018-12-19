/*
* Prácticas de IG 
* Copyright Domingo Martín Perandrés 2014-218
* dmartin@ugr.es
* 
* GPL 3
*/

#ifndef OBJECT3D_SWEEP_BASIC_H
#define OBJECT3D_SWEEP_BASIC_H

#include "object3d.h"

class _object3d_sweep_basic:public _object3D
{
public:

  void create(vector<_vertex2f> &Curve, unsigned int Num_horizontal_divisions1);

protected:
  unsigned int Num_vertical_divisions;
  unsigned int Num_horizontal_divisions;

private:
  unsigned int linear_position(int Row,int Col){return (Col%Num_horizontal_divisions)*(Num_vertical_divisions+1)+Row;};
};

#endif
