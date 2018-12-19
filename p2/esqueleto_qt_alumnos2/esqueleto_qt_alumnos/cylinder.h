#ifndef CYLINDER_H
#define CYLINDER_H

#include "object3d_sweep_basic.h"

class _cylinder : public _object3d_sweep_basic
{
public:
    _cylinder();
    void create(unsigned int Divisions);
};

#endif // CYLINDER_H
