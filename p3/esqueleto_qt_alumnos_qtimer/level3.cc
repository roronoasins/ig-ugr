/*
* Prácticas de IG
* Copyright Domingo Martín Perandrés 2014-218
* dmartin@ugr.es
*
* GPL 3
*/

#include "level3.h"

/**
*
*@param
*@returns
*/

void _level3::create(float Lenght1, float Width1)
{
  Lenght=Lenght1;
  Width=Width1;

  Level2.create(1,0.5);
}


/**
*
*@param
*@returns
*/

void _level3::rot1(){
    alpha+=10;
}

void _level3::rot2(){
    alpha-=10;
}

void _level3::draw_point()
{
  glMatrixMode(GL_MODELVIEW);
  // front right
  glPushMatrix();
  glTranslatef(Width/2,0,Lenght/2);
  glRotatef(-alpha,0,0,1);
  Level2.draw_point();
  glPopMatrix();

  // front left
  glPushMatrix();
  glTranslatef(-Width/2,0,Lenght/2);
  glRotatef(alpha,0,0,1);
  Level2.draw_point();
  glPopMatrix();

  // bottom right
  glPushMatrix();
  glTranslatef(Width/2,0,-Lenght/2);
  glRotatef(-alpha,0,0,1);
  Level2.draw_point();
  glPopMatrix();

  // bottom left
  glPushMatrix();
  glTranslatef(-Width/2,0,-Lenght/2);
  glRotatef(alpha,0,0,1);
  Level2.draw_point();
  glPopMatrix();
}

/**
*
*@param
*@returns
*/

void _level3::draw_line()
{
  glMatrixMode(GL_MODELVIEW);
  // front right
  glPushMatrix();
  glTranslatef(Width/2,0,Lenght/2);
  glRotatef(-alpha,0,0,1);
  Level2.draw_line();
  glPopMatrix();

  // front left
  glPushMatrix();
  glTranslatef(-Width/2,0,Lenght/2);
  glRotatef(alpha,0,0,1);
  Level2.draw_line();
  glPopMatrix();

  // bottom right
  glPushMatrix();
  glTranslatef(Width/2,0,-Lenght/2);
  glRotatef(-alpha,0,0,1);
  Level2.draw_line();
  glPopMatrix();

  // bottom left
  glPushMatrix();
  glTranslatef(-Width/2,0,-Lenght/2);
  glRotatef(alpha,0,0,1);
  Level2.draw_line();
  glPopMatrix();
}

/**
*
*@param
*@returns
*/

void _level3::draw_fill()
{
  glMatrixMode(GL_MODELVIEW);
  // front right
  glPushMatrix();
  glTranslatef(Width/2,0,Lenght/2);
  glRotatef(-90,0,0,1);
  Level2.draw_fill();
  glPopMatrix();

  // front left
  glPushMatrix();
  glTranslatef(-Width/2,0,Lenght/2);
  glRotatef(90,0,0,1);
  Level2.draw_fill();
  glPopMatrix();

  // bottom right
  glPushMatrix();
  glTranslatef(Width/2,0,-Lenght/2);
  glRotatef(-90,0,0,1);
  Level2.draw_fill();
  glPopMatrix();

  // bottom left
  glPushMatrix();
  glTranslatef(-Width/2,0,-Lenght/2);
  glRotatef(90,0,0,1);
  Level2.draw_fill();
  glPopMatrix();
}

/**
*
*@param
*@returns
*/

void _level3::draw_chess()
{
  glMatrixMode(GL_MODELVIEW);
  // front right
  glPushMatrix();
  glTranslatef(Width/2,0,Lenght/2);
  glRotatef(-90,0,0,1);
  Level2.draw_chess();
  glPopMatrix();

  // front left
  glPushMatrix();
  glTranslatef(-Width/2,0,Lenght/2);
  glRotatef(90,0,0,1);
  Level2.draw_chess();
  glPopMatrix();

  // bottom right
  glPushMatrix();
  glTranslatef(Width/2,0,-Lenght/2);
  glRotatef(-90,0,0,1);
  Level2.draw_chess();
  glPopMatrix();

  // bottom left
  glPushMatrix();
  glTranslatef(-Width/2,0,-Lenght/2);
  glRotatef(90,0,0,1);
  Level2.draw_chess();
  glPopMatrix();
}


