#include "cube.h"

_cube::_cube(float Size)
{
    Vertices.resize(8);

    Vertices[0]=_vertex3f(-Size,-Size,Size);
    Vertices[1]=_vertex3f(Size,-Size,Size);
    Vertices[2]=_vertex3f(-Size,Size,Size);
    Vertices[3]=_vertex3f(Size,Size,Size);
    Vertices[4]=_vertex3f(-Size,-Size,-Size);
    Vertices[5]=_vertex3f(Size,-Size,-Size);
    Vertices[6]=_vertex3f(-Size,Size,-Size);
    Vertices[7]=_vertex3f(Size,Size,-Size);

    /*GLfloat texcoord1s[] = { 0.0,0.0, 0.33,0.0, 0.33,0.33,
                               0.0,0.0, 0.33,0.33, 0.0,0.33,

                             0.33,0.0, 0.66,0.0, 0.66,0.33,
                             0.33,0.0, 0.66,0.33, 0.33,0.33,

                             0.66,0.0, 1.0,0.0,1.0,0.33,
                             0.66,0.0, 1.0,0.33, 0.66,0.33,

                             0.0,0.33, 0.33,0.33, 0.33,0.66,
                             0.0,0.33, 0.33,0.66, 0.0,0.66,

                             0.33,0.33, 0.66,0.33, 0.66,0.66,
                             0.33,0.33, 0.66,0.66, 0.33,0.66,

                             0.66,0.33, 1.0,0.33, 1.0,0.66,
                             0.66,0.33, 1.0,0.66, 0.66,0.66

                                };*/

    GLfloat texcoord1s[] = { 0.0,0.0, 0.33,0.0, 0.33,0.33,
                                   0.0,0.0, 0.33,0.33, 0.0,0.33,

                             0.66,0.0, 0.99,0.0, 0.99,0.33,
                             0.66,0.0, 0.99,0.33, 0.66,0.33,

                             0.33,0.0, 0.66,0.0, 0.66,0.33,
                             0.33,0.0, 0.66,0.33, 0.33,0.33,

                             0.0,0.33, 0.33,0.33, 0.33,0.66,
                             0.0,0.33, 0.33,0.66, 0.0,0.66,

                             0.33,0.33, 0.66,0.33, 0.66,0.66,
                             0.33,0.33, 0.66,0.66, 0.33,0.66,

                             0.66,0.33, 0.99,0.33, 0.99,0.66,
                             0.66,0.33, 0.99,0.66, 0.66,0.66 };// ruby texture

    Triangles.resize(12);

    Triangles[0]=_vertex3ui(0,1,3);
    Triangles[1]=_vertex3ui(0,3,2);

    Triangles[2]=_vertex3ui(5,4,6);
    Triangles[3]=_vertex3ui(5,6,7);

    Triangles[4]=_vertex3ui(1,5,7);
    Triangles[5]=_vertex3ui(1,7,3);

    Triangles[6]=_vertex3ui(4,0,2);
    Triangles[7]=_vertex3ui(4,2,6);

    Triangles[8]=_vertex3ui(7,6,2);
    Triangles[9]=_vertex3ui(7,2,3);

    Triangles[11]=_vertex3ui(4,1,0);
    Triangles[10]=_vertex3ui(4,5,1);

    int t=0;
    for (int i=0; i < Triangles.size()*6; i++) {
        texcoords[i] = texcoord1s[i];
    }

}

void _cube::draw_texture()
{
    glEnable(GL_TEXTURE_2D);
    int j=0;

    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
    glBegin(GL_TRIANGLES);
    for (unsigned int i=0;i<Triangles.size();i++){
        j=6*i;
        glTexCoord2f(texcoords[j], texcoords[j+1]);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._0]);
        glTexCoord2f(texcoords[j+2], texcoords[j+3]);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._1]);
        glTexCoord2f(texcoords[j+4], texcoords[j+5]);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._2]);
    }
    glEnd();
    glDisable(GL_TEXTURE_2D);
}
