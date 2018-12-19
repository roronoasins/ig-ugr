#ifndef BASE_H
#define BASE_H

#include "arm3.h"
#include "cube.h"

class _base : public _arm3
{
public:
    void create();
    void draw_point();
    void draw_line();
    void draw_fill();
    void draw_chess();
    void draw_illumination_flat_shading();
    void rotate_left();
    void rotate_right();
    void increase_rotate_speed();
    void decrease_rotate_speed();

    float angle_rotate=0, speed_rotate=5;
protected:
  _cube Cube;
};

#endif // BASE_H
