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
    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
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

void _object3D::draw_chess()
{
    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
    glBegin(GL_TRIANGLES);
    for (unsigned int i=0;i<Triangles.size();i++){
        if(i%2==0)
            glColor3fv((GLfloat *) &BLACK);
        else
            glColor3fv((GLfloat *) &YEllOW);
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

void _object3D::draw_illumination_flat_shading()
{
    if (!Triangles.empty()){
        compute_triangles_normals();
        compute_vertices_normals();

        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        glPushMatrix();
        GLfloat color[] = {0.0, 1.0, 0.0, 1.0};
       // glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, color);
        GLfloat ambient[] = {1.0, 1.0, 1.0, 1.0};
        //glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);
        GLfloat white[] = { 1.0f, 1.0f, 1.0f, 1.0f };
       // glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, white);
        //glColor3fv((GLfloat *) &GREEN);
        glPopMatrix();
        glShadeModel(GL_FLAT);

        glBegin(GL_TRIANGLES);

        for (unsigned int i = 0; i<Triangles.size(); i++){
            glNormal3f(Triangles_normals[i].x, Triangles_normals[i].y, Triangles_normals[i].z);
            //glNormal3fv((GLfloat *) &Vertices_normals[Triangles[i]]);

            glVertex3fv((GLfloat *) &Vertices[Triangles[i]._0]);
            glVertex3fv((GLfloat *) &Vertices[Triangles[i]._1]);
            glVertex3fv((GLfloat *) &Vertices[Triangles[i]._2]);
        }
        glEnd();
    }
}

/**
*
*@param
*@returns
*/

void _object3D::draw_illumination_smooth_shading()
{
    if (!Triangles.empty()){
        compute_triangles_normals();
        compute_vertices_normals();

        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        glPushMatrix();
        GLfloat color[] = {1.0, 1.0, 0.0, 1.0};
       // glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, color);
        GLfloat ambient[] = {1.0, 1.0, 1.0, 1.0};
       // glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);
        GLfloat white[] = { 1.0f, 1.0f, 1.0f, 1.0f };
       // glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, white);
        //glColor3fv((GLfloat *) &YEllOW);
        glPopMatrix();
        glShadeModel(GL_SMOOTH);

        glBegin(GL_TRIANGLES);
        for (unsigned int i = 0; i<Triangles.size(); i++){
            glNormal3f(Vertices_normals[Triangles[i]._0].x, Vertices_normals[Triangles[i]._0].y, Vertices_normals[Triangles[i]._0].z);
            glVertex3f(Vertices[Triangles[i]._0].x, Vertices[Triangles[i]._0].y, Vertices[Triangles[i]._0].z);
            //glNormal3fv((GLfloat *) &Vertices_normals[Triangles[i]._0]);
           // glVertex3fv((GLfloat *) &Vertices[Triangles[i]._0]);

            glNormal3f(Vertices_normals[Triangles[i]._1].x, Vertices_normals[Triangles[i]._1].y, Vertices_normals[Triangles[i]._1].z);
            glVertex3f(Vertices[Triangles[i]._1].x, Vertices[Triangles[i]._1].y, Vertices[Triangles[i]._1].z);
            //glNormal3fv((GLfloat *) &Vertices_normals[Triangles[i]._1]);
            //glVertex3fv((GLfloat *) &Vertices[Triangles[i]._1]);

            glNormal3f(Vertices_normals[Triangles[i]._2].x, Vertices_normals[Triangles[i]._2].y, Vertices_normals[Triangles[i]._2].z);
            glVertex3f(Vertices[Triangles[i]._2].x, Vertices[Triangles[i]._2].y, Vertices[Triangles[i]._2].z);
          //  glNormal3fv((GLfloat *) &Vertices_normals[Triangles[i]._2]);
          //  glVertex3fv((GLfloat *) &Vertices[Triangles[i]._2]);

        }
        glEnd();
    }
}


/**
*
*@param
*@returns
*/

void _object3D::draw_texture()
{

    glEnable(GL_TEXTURE_2D);
    glEnable(GL_TEXTURE_GEN_S);
    glEnable(GL_TEXTURE_GEN_T);
    glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
    glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
    draw_fill();
    glDisable(GL_TEXTURE_GEN_S);
    glDisable(GL_TEXTURE_GEN_T);
    glDisable(GL_TEXTURE_2D);
}

/**
*
*@param
*@returns
*/

void _object3D::draw_texture_illumination_flat_shading()
{
    compute_triangles_normals();
    compute_vertices_normals();

    glEnable(GL_TEXTURE_2D);
    glEnable(GL_TEXTURE_GEN_S);
    glEnable(GL_TEXTURE_GEN_T);
    glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
    glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
    draw_illumination_flat_shading();
    glDisable(GL_TEXTURE_GEN_S);
    glDisable(GL_TEXTURE_GEN_T);
    glDisable(GL_TEXTURE_2D);
}

/**
*
*@param
*@returns
*/

void _object3D::draw_texture_illumination_smooth_shading()
{
    compute_triangles_normals();
    compute_vertices_normals();

    glEnable(GL_TEXTURE_2D);
    glEnable(GL_TEXTURE_GEN_S);
    glEnable(GL_TEXTURE_GEN_T);
    glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
    glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
    glShadeModel(GL_SMOOTH);
    draw_illumination_smooth_shading();
    glDisable(GL_TEXTURE_GEN_S);
    glDisable(GL_TEXTURE_GEN_T);
    glDisable(GL_TEXTURE_2D);
}


/**
*
*@param
*@returns
*/

void _object3D::compute_triangles_normals()
{
    _vertex3f a, b, n;
    float module;

    for(unsigned int i=0; i < Triangles.size(); ++i) {
        a(Vertices[Triangles[i]._1].x - Vertices[Triangles[i]._0].x,
          Vertices[Triangles[i]._1].y - Vertices[Triangles[i]._0].y,
          Vertices[Triangles[i]._1].z - Vertices[Triangles[i]._0].z);

        b(Vertices[Triangles[i]._2].x - Vertices[Triangles[i]._0].x,
          Vertices[Triangles[i]._2].y - Vertices[Triangles[i]._0].y,
          Vertices[Triangles[i]._2].z - Vertices[Triangles[i]._0].z);

        /*  Producto vectorial

                         |ay  az|        |ax  az|         |ax  ay|
           n = axb =     |by  bz| * x  - |bx  bz| * y   + |bx  by| * z = (aybz  - azby)x + (azbx - axbz)y + (axby - aybx)z
        */

        n((a.y * b.z) - (a.z * b.y),
         -((a.x * b.z) - (a.z * b.x)),
          (a.x * b.y) - (a.y * b.x));

        //Normalizacion de la normal
        module = sqrt( pow(n.x, 2) + pow(n.y, 2) + pow(n.z, 2) );
        n/=module;

        Triangles_normals.push_back(n);
    }
}

/**
*
*@param
*@returns
*/

void _object3D::compute_vertices_normals()
{
    float module;

    if (!Vertices.empty()) {
        Vertices_normals.resize(Vertices.size());   //Cada vector tiene su normal
        num_normales.resize(Vertices.size());

        for (unsigned int i = 0; i < Triangles.size(); i++){
           Vertices_normals[Triangles[i]._0] += Triangles_normals[i];
           num_normales[Triangles[i]._0]++;
           Vertices_normals[Triangles[i]._1] += Triangles_normals[i];
           num_normales[Triangles[i]._1]++;
           Vertices_normals[Triangles[i]._2] += Triangles_normals[i];
           num_normales[Triangles[i]._2]++;
        }

        for (unsigned int i = 0; i < Vertices_normals.size(); i++){

           module = sqrt( pow(Vertices_normals[i].x, 2) + pow(Vertices_normals[i].y, 2) + pow(Vertices_normals[i].z, 2) );

           Vertices_normals[i] /= num_normales[i];
           Vertices_normals[i] /= module;
        }


    }
}

