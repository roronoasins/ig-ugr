#include "finger.h"

void _finger::create(float Height1, float Width1)
{
  Height=Height1;
  Width=Width1;
}

void _finger::draw_line()
{
  glMatrixMode(GL_MODELVIEW);
  glPushMatrix();
  glTranslatef(0,Height/4,0);
  glScalef(Width/2,Height/2,Width/2);
  Pyramid.draw_line();
  glPopMatrix();
}

void _finger::draw_point()
{
  glMatrixMode(GL_MODELVIEW);
  glPushMatrix();
  glTranslatef(0,Height/4,0);
  glScalef(Width/2,Height/2,Width/2);
  Pyramid.draw_point();
  glPopMatrix();
}

void _finger::draw_fill()
{
  glMatrixMode(GL_MODELVIEW);
  glPushMatrix();
  glTranslatef(0,Height/4,0);
  glScalef(Width/2,Height/2,Width/2);
  Pyramid.draw_fill();
  glPopMatrix();
}

void _finger::draw_chess()
{
  glMatrixMode(GL_MODELVIEW);
  glPushMatrix();
  glTranslatef(0,Height/4,0);
  glScalef(Width/2,Height/2,Width/2);
  Pyramid.draw_chess();
  glPopMatrix();
}
