#ifndef PALM_H
#define PALM_H

#include "pyramid.h"

class _palm : public _pyramid
{
public:
    void create(float Height1=1, float Width1=0.5);
    void draw_point();
    void draw_line();
    void draw_fill();
    void draw_chess();
    void draw_illumination_flat_shading();
    float getHeight();
    float getWidth();
protected:
  float Height;
  float Width;
  _pyramid Pyramid;
};

#endif // PALM_H
