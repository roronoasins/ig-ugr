#ifndef ARM2_H
#define ARM2_H

#include "cylinder.h"
#include "sphere.h"
#include "arm1.h"

class _arm2:public _arm1
{
public:
    void create();
    void draw_point();
    void draw_line();
    void draw_fill();
    void draw_chess();
    void lean_forward1();
    void lean_backward1();
    void increase_arm1_speed();
    void decrease_arm1_speed();

    float angle_arm1=0, speed_arm1=5;
protected:
  _sphere Sphere;
  _cylinder Cylinder;
};

#endif // ARM2_H
