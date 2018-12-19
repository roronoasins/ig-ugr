#ifndef CONE_H
#define CONE_H

#include "object3d_sweep_basic.h"

class _cone : public _object3d_sweep_basic
{
public:
    _cone();
    void create(unsigned int Divisions);
};

#endif // CONE_H
