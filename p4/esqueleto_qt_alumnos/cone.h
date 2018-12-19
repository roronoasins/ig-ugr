/*
* Prácticas de IG
* Copyright Domingo Martín Perandrés 2014-218
* dmartin@ugr.es
*
* GPL 3
*/

#include "object3d_sweep_basic.h"

class _cone:public _object3d_sweep_basic
{
public:

  void create(unsigned int Num_horizontal_divisions1=3,float Radius1=0.5, float Height1=1);
};
