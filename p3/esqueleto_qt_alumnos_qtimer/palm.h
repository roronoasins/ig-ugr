#ifndef PALM_H
#define PALM_H

#include "pyramid.h"

class _palm
{
public:
    void create(float Height1=1, float Width1=0.5);
    void draw_point();
    void draw_line();
    void draw_fill();
    void draw_chess();
    float getHeight();
    float getWidth();
protected:
  float Height;
  float Width;
  _pyramid Pyramid;
};

#endif // PALM_H
