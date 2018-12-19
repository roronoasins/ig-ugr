/*
* Prácticas de IG
* Copyright Domingo Martín Perandrés 2014-218
* dmartin@ugr.es
*
* GPL 3
*/

#ifndef OBJECT_PLY_H
#define OBJECT_PLY_H

#include "object3d.h"

class _object_ply:public _object3D
{
public:
  void create(vector<float> &Coordinates,vector<unsigned int> &Positions);
};

#endif
