/*
* Prácticas de IG
* Copyright Domingo Martín Perandrés 2014-218
* dmartin@ugr.es
*
* GPL 3
*/

#include "level2.h"

/**
*
*@param
*@returns
*/

void _level2::create(float Height1, float Width1)
{
  Height=Height1;
  Width=Width1;
}


/**
*
*@param
*@returns
*/

void _level2::draw_point()
{
  glMatrixMode(GL_MODELVIEW);
  glPushMatrix();
  glTranslatef(0,Height/2,0);
  glScalef(Width,Height,Width);
  Tetrahedron.draw_point();
  glPopMatrix();
}

/**
*
*@param
*@returns
*/

void _level2::draw_line()
{
  glMatrixMode(GL_MODELVIEW);
  glPushMatrix();
  glTranslatef(0,Height/2,0);
  glScalef(Width,Height,Width);
  Tetrahedron.draw_line();
  glPopMatrix();
}

/**
*
*@param
*@returns
*/

void _level2::draw_fill()
{
  glMatrixMode(GL_MODELVIEW);
  glPushMatrix();
  glTranslatef(0,Height/2,0);
  glScalef(Width,Height,Width);
  Tetrahedron.draw_fill();
  glPopMatrix();
}

/**
*
*@param
*@returns
*/

void _level2::draw_chess()
{
  glMatrixMode(GL_MODELVIEW);
  glPushMatrix();
  glTranslatef(0,Height/2,0);
  glScalef(Width,Height,Width);
  Tetrahedron.draw_chess();
  glPopMatrix();
}
