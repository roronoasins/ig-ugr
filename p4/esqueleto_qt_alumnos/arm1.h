#ifndef ARM1_H
#define ARM1_H

#include "hand.h"
#include "cylinder.h"
#include "sphere.h"

class _arm1:public _hand
{
public:
    void create();
    void draw_line();
    void draw_point();
    void draw_fill();
    void draw_chess();
    void draw_illumination_flat_shading();
    void hand_forward();
    void hand_backward();
    void increase_hand_speed();
    void decrease_hand_speed();

    float angle_hand=0, speed_hand=5;
protected:
  _sphere Sphere;
  _cylinder Cylinder;
};

#endif // ARM1_H
