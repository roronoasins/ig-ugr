#ifndef OBJECT_PLY_H
#define OBJECT_PLY_H

#include "object3d.h"
#include "object3d_sweep_basic.h"

class _object_ply : public _object3D
{
public:
    _object_ply();
    void create(vector<float> &Coordinates, vector<unsigned int> &Positions);
};

#endif // OBJECT_PLY_H
