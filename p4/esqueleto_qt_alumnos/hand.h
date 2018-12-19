#ifndef HAND_H
#define HAND_H

#include "finger.h"
#include "palm.h"

class _hand : public _palm
{
public:
    void create(float Height1=1.0, float Width1=0.5);
    void draw_point();
    void draw_line();
    void draw_fill();
    void draw_chess();
    void draw_illumination_flat_shading();
    void open_hand();
    void close_hand();
    void increase_fingers_speed();
    void decrease_fingers_speed();

    float angle_fingers=0, speed_fingers=1;

protected:
  float Height;
  float Width;
  _palm Palm;
  _finger F1, F2, F3, F4;
};

#endif // HAND_H
