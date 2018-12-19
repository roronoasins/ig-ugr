/*
* Prácticas de IG
* Copyright Domingo Martín Perandrés 2014-218
* dmartin@ugr.es
*
* GPL 3
*/

#include "sphere.h"

/**
*
*@param
*@returns
*/

void _sphere::create(unsigned int Divisions,float radio)
{
    vector<_vertex2f> Curve;
    this->radio = radio;
    float angulo;
    for(int i=0; i <= Divisions; i++){
        angulo = i*(180/Divisions);
        angulo += 270;  //Obtenemos el equivalente en la parte inferior
        Curve.push_back(_vertex2f(radio*cos(angulo*M_PI/180),radio*sin(angulo*M_PI/180)));
    }
    float dist = sqrt(pow(Curve[0].x-Curve[Curve.size()-1].x,2)+pow(Curve[0].y-Curve[Curve.size()-1].y,2));
    center = _vertex2f(abs(Curve[0].x)-dist, abs(Curve[0].y)-dist);
    _object3d_sweep_basic::create(Curve,Divisions);
}

/**
*
*@param
*@returns
*/

void _sphere::compute_vertices_normals()
{
    float module;

    if (!Vertices.empty()) {
        Vertices_normals.resize(Vertices.size());   //Cada vector tiene su normal
        num_normales.resize(Vertices.size());

        for (unsigned int i = 0; i < Vertices.size(); i++){//if x<0 +radio else - radio
           Vertices_normals[i] = _vertex3f(Vertices[i].x-center.x, Vertices[i].y-center.y, Vertices[i].z);


           module = sqrt( pow(Vertices_normals[i].x, 2) + pow(Vertices_normals[i].y, 2) + pow(Vertices_normals[i].z, 2) );

           //Vertices_normals[i] /= num_normales[i];
           Vertices_normals[i] /= module;
        }
    }
}

void _sphere::draw_illumination_flat_shading()
{
    if (!Triangles.empty()){
        compute_triangles_normals();
        this->compute_vertices_normals();

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

void _sphere::draw_illumination_smooth_shading()
{
    if (!Triangles.empty()){
        compute_triangles_normals();
        this->compute_vertices_normals();

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


void _sphere::draw_texture()
{

}


