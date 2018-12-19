#ifndef SPHERE_H
#define SPHERE_H

#include "object3d_sweep_basic.h"

class _sphere : public _object3d_sweep_basic
{
public:
    _sphere();
    void create(unsigned int Divisions, float radio);
};

#endif // SPHERE_H
