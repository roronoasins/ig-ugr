#include "arm2.h"

void _arm2::create()
{
  Sphere.create(20, 0.4);
  Cylinder.create(20);
  _arm1::create();
}

void _arm2::draw_line()
{
  glMatrixMode(GL_MODELVIEW);
  glPushMatrix();
  glTranslatef(0,Sphere.radio,0);
  Sphere.draw_line();
  glPopMatrix();

  glMatrixMode(GL_MODELVIEW);
  glPushMatrix();
  glTranslatef(0,1.25+Sphere.radio*2,0);
  glScalef(0.5,2.5,0.5);
  Cylinder.draw_line();
  glPopMatrix();

  glMatrixMode(GL_MODELVIEW);
  glPushMatrix();
  glTranslatef(0,2.5+Sphere.radio*2+0.4,0);
  glRotatef(angle_arm1,1,0,0);
  glTranslatef(0,-0.4,0);       //Colocamos en origen
  _arm1::draw_line();
  glPopMatrix();
}

void _arm2::draw_point()
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,Sphere.radio,0);
    Sphere.draw_point();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,1.25+Sphere.radio*2,0);
    glScalef(0.5,2.5,0.5);
    Cylinder.draw_point();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,2.5+Sphere.radio*2+0.4,0);
    glRotatef(angle_arm1,1,0,0);
    glTranslatef(0,-0.4,0);       //Colocamos en origen
    _arm1::draw_point();
    glPopMatrix();
}

void _arm2::draw_fill()
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,Sphere.radio,0);
    Sphere.draw_fill();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,1.25+Sphere.radio*2,0);
    glScalef(0.5,2.5,0.5);
    Cylinder.draw_fill();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,2.5+Sphere.radio*2+0.4,0);
    glRotatef(angle_arm1,1,0,0);
    glTranslatef(0,-0.4,0);       //Colocamos en origen
    _arm1::draw_fill();
    glPopMatrix();
}

void _arm2::draw_chess()
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,Sphere.radio,0);
    Sphere.draw_chess();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,1.25+Sphere.radio*2,0);
    glScalef(0.5,2.5,0.5);
    Cylinder.draw_chess();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,2.5+Sphere.radio*2+0.4,0);
    glRotatef(angle_arm1,1,0,0);
    glTranslatef(0,-0.4,0);       //Colocamos en origen
    _arm1::draw_chess();
    glPopMatrix();
}

void _arm2::draw_illumination_flat_shading()
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,Sphere.radio,0);
    Sphere.draw_illumination_flat_shading();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,1.25+Sphere.radio*2,0);
    glScalef(0.5,2.5,0.5);
    Cylinder.draw_illumination_flat_shading();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,2.5+Sphere.radio*2+0.4,0);
    glRotatef(angle_arm1,1,0,0);
    glTranslatef(0,-0.4,0);       //Colocamos en origen
    _arm1::draw_illumination_flat_shading();
    glPopMatrix();
}

void _arm2::lean_forward1()   {if(angle_arm1<75)angle_arm1+=speed_arm1;}
void _arm2::lean_backward1()  {if(angle_arm1>-75) angle_arm1-=speed_arm1;}
void _arm2::increase_arm1_speed()   {if(speed_arm1<10)  speed_arm1++;}
void _arm2::decrease_arm1_speed()   {if(speed_arm1>2)  speed_arm1--;}
