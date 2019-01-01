/*
* Prácticas de IG
* Copyright Domingo Martín Perandrés 2014-218
* dmartin@ugr.es
*
* GPL 3
*/

#include "object3d.h"

using namespace _colors_ne;

/**
*
*@param
*@returns
*/

void _object3D::draw_line()
{
  glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
  glPolygonOffset(-1,1);
  glBegin(GL_TRIANGLES);
    for (unsigned int i=0;i<Triangles.size();i++){
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._0]);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._1]);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._2]);
    }
  glEnd();
}


/**
*
*@param
*@returns
*/

void _object3D::draw_fill()
{
    glPolygonMode(GL_FRONT,GL_FILL);
    glPolygonOffset(-1,1);
    glBegin(GL_TRIANGLES);
    for (unsigned int i=0;i<Triangles.size();i++){
        if( i == Selected_triangle )    glColor3fv((GLfloat *) &YEllOW);    //El triangulo que se seleccione con pick() se dibujara de amarillo
        else glColor3fv((GLfloat *) &BLUE);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._0]);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._1]);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._2]);
    }
    glEnd();
}

/**
*
*@param
*@returns
*/

void _object3D::draw_selection()
{



    /*
     * Los identificadores posibles serán del 0 al 16777215(16777216 pero quitado el blanco, como representante de ninguna selección)
     * debido a los 24 bits para representar las tonalidades RGB.
     *
     * Componente azul: 0 - 255
     * Componente verde: 256 - 65535
     * Componente roja: 65535 - 16777215
     *
     * Para convertir cada identificador a RGB bastaria con: Dividir el id entre 65535 siendo el cociente la componente roja,
     * el resto lo dividimos entre 256 quedando como cociente la componente verde y el resto la azul.
     *
     * Tras esa parte solo queda normalizar el rgb obtenido.
     *
     * */

    _vertex3f id_color;
    _vertex4f color;

    glPolygonMode(GL_FRONT,GL_FILL);
    glPolygonOffset(-1,1);
    glBegin(GL_TRIANGLES);
    for (unsigned int i=0;i<Triangles.size();i++){
        id_color.r = (i & 0x00FF0000) >> 16;
        id_color.g = (i & 0x0000FF00) >> 8;
        id_color.b = i & 0x000000FF;
        id_color /= 255.0;
        color = _vertex4f(id_color.r,id_color.g,id_color.b,1);

        glColor3fv((GLfloat *) &color);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._0]);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._1]);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._2]);
    }
    glEnd();

}
