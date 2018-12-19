#include "palm.h"

void _palm::create(float Height1, float Width1)
{
  Height=Height1;
  Width=Width1;
}


void _palm::draw_line()
{
  glMatrixMode(GL_MODELVIEW);
  glPushMatrix();
  glTranslatef(0,Height/4,0);
  glScalef(Width+0.3,Height/2,Width+0.3);
  glRotatef(180,0,0,1);
  Pyramid.draw_line();
  glPopMatrix();
}

void _palm::draw_point()
{
  glMatrixMode(GL_MODELVIEW);
  glPushMatrix();
  glTranslatef(0,Height/4,0);
  glScalef(Width+0.3,Height/2,Width+0.3);
  glRotatef(180,0,0,1);
  Pyramid.draw_point();
  glPopMatrix();
}

void _palm::draw_fill()
{
  glMatrixMode(GL_MODELVIEW);
  glPushMatrix();
  glTranslatef(0,Height/4,0);
  glScalef(Width+0.3,Height/2,Width+0.3);
  glRotatef(180,0,0,1);
  Pyramid.draw_fill();
  glPopMatrix();
}

void _palm::draw_chess()
{
  glMatrixMode(GL_MODELVIEW);
  glPushMatrix();
  glTranslatef(0,Height/4,0);
  glScalef(Width+0.3,Height/2,Width+0.3);
  glRotatef(180,0,0,1);
  Pyramid.draw_chess();
  glPopMatrix();
}

float _palm::getHeight(){
    return Height;
}

float _palm::getWidth(){
    return Width;
}
