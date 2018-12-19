#ifndef ARM3_H
#define ARM3_H

#include "cylinder.h"
#include "sphere.h"
#include "arm2.h"

class _arm3: public _arm2
{
public:
    void create();
    void draw_line();
    void draw_point();
    void draw_fill();
    void draw_chess();
    void lean_forward2();
    void lean_backward2();
    void increase_arm2_speed();
    void decrease_arm2_speed();

    float angle_arm2=0, speed_arm2=5;
protected:
  _sphere Sphere;
  _cylinder Cylinder;
};

#endif // ARM3_H
