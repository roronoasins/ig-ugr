#ifndef CUBE_H
#define CUBE_H

#include "object3d.h"

class _cube:public _object3D
{
public:
    _cube(float Size=1.0);

    void draw_texture();

private:
    vector<_vertex2f> tex;
    GLfloat texcoords[12*6];
};

#endif // CUBE_H
