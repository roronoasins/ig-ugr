#include "arm3.h"

void _arm3::create()
{
  Cylinder.create(20);
  _arm2::create();
}

void _arm3::draw_line()
{
  glMatrixMode(GL_MODELVIEW);
  glPushMatrix();
  glTranslatef(0,1.25,0);
  glScalef(0.5,2.5,0.5);
  Cylinder.draw_line();
  glPopMatrix();

  glMatrixMode(GL_MODELVIEW);
  glPushMatrix();
  glTranslatef(0,2.5+0.4,0);
  glRotatef(angle_arm2,1,0,0);
  glTranslatef(0,-0.4,0);       //Colocamos en origen
  _arm2::draw_line();
  glPopMatrix();
}

void _arm3::draw_point()
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,1.25,0);
    glScalef(0.5,2.5,0.5);
    Cylinder.draw_point();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,2.5+0.4,0);
    glRotatef(angle_arm2,1,0,0);
    glTranslatef(0,-0.4,0);       //Colocamos en origen
    _arm2::draw_point();
    glPopMatrix();
}

void _arm3::draw_fill()
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,1.25,0);
    glScalef(0.5,2.5,0.5);
    Cylinder.draw_fill();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,2.5+0.4,0);
    glRotatef(angle_arm2,1,0,0);
    glTranslatef(0,-0.4,0);       //Colocamos en origen
    _arm2::draw_fill();
    glPopMatrix();
}

void _arm3::draw_chess()
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,1.25,0);
    glScalef(0.5,2.5,0.5);
    Cylinder.draw_chess();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,2.5+0.4,0);
    glRotatef(angle_arm2,1,0,0);
    glTranslatef(0,-0.4,0);       //Colocamos en origen
    _arm2::draw_chess();
    glPopMatrix();
}

void _arm3::draw_illumination_flat_shading()
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,1.25,0);
    glScalef(0.5,2.5,0.5);
    Cylinder.draw_illumination_flat_shading();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,2.5+0.4,0);
    glRotatef(angle_arm2,1,0,0);
    glTranslatef(0,-0.4,0);       //Colocamos en origen
    _arm2::draw_illumination_flat_shading();
    glPopMatrix();
}

void _arm3::lean_forward2()   {if(angle_arm2<45) angle_arm2+=speed_arm2;}
void _arm3::lean_backward2()  {if(angle_arm2>-45) angle_arm2-=speed_arm2;}
void _arm3::increase_arm2_speed()   {if(speed_arm2<10)  speed_arm2++;}
void _arm3::decrease_arm2_speed()   {if(speed_arm2>2)  speed_arm2--;}
