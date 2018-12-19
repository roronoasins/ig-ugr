#include "base.h"

void _base::create()
{
  _arm3::create();
}

void _base::draw_line()
{
  glMatrixMode(GL_MODELVIEW);
  glPushMatrix();
  glScalef(8,1,8);
  glTranslatef(0,0.5,0);
  Cube.draw_line();
  glPopMatrix();

  glMatrixMode(GL_MODELVIEW);
  glPushMatrix();
  glScalef(2,2,2);
  glTranslatef(0,0.5,0);
  glRotatef(angle_rotate,0,1,0);
  _arm3::draw_line();
  glPopMatrix();
}

void _base::draw_point()
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(8,1,8);
    glTranslatef(0,0.5,0);
    Cube.draw_point();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(2,2,2);
    glTranslatef(0,0.5,0);
    glRotatef(angle_rotate,0,1,0);
    _arm3::draw_point();
    glPopMatrix();
}

void _base::draw_fill()
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(8,1,8);
    glTranslatef(0,0.5,0);
    Cube.draw_fill();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(2,2,2);
    glTranslatef(0,0.5,0);
    glRotatef(angle_rotate,0,1,0);
    _arm3::draw_fill();
    glPopMatrix();
}

void _base::draw_chess()
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(8,1,8);
    glTranslatef(0,0.5,0);
    Cube.draw_chess();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(2,2,2);
    glTranslatef(0,0.5,0);
    glRotatef(angle_rotate,0,1,0);
    _arm3::draw_chess();
    glPopMatrix();
}

void _base::draw_illumination_flat_shading()
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(8,1,8);
    glTranslatef(0,0.5,0);
    Cube.draw_illumination_flat_shading();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(2,2,2);
    glTranslatef(0,0.5,0);
    glRotatef(angle_rotate,0,1,0);
    _arm3::draw_illumination_flat_shading();
    glPopMatrix();
}


void _base::rotate_left()   {angle_rotate+=speed_rotate;}
void _base::rotate_right()  {angle_rotate-=speed_rotate;}
void _base::increase_rotate_speed()   {if(speed_rotate<20)  speed_rotate++;}
void _base::decrease_rotate_speed()   {if(speed_rotate>2)  speed_rotate--;}
