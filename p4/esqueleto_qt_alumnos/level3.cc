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

void _level3::draw_point()
{
  glMatrixMode(GL_MODELVIEW);
  // front right
  glPushMatrix();
  glTranslatef(Width/2,0,Lenght/2);
  glRotatef(-90,0,0,1);
  Level2.draw_point();
  glPopMatrix();

  // front left
  glPushMatrix();
  glTranslatef(-Width/2,0,Lenght/2);
  glRotatef(90,0,0,1);
  Level2.draw_point();
  glPopMatrix();

  // bottom right
  glPushMatrix();
  glTranslatef(Width/2,0,-Lenght/2);
  glRotatef(-90,0,0,1);
  Level2.draw_point();
  glPopMatrix();

  // bottom left
  glPushMatrix();
  glTranslatef(-Width/2,0,-Lenght/2);
  glRotatef(90,0,0,1);
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
  glRotatef(-90,0,0,1);
  Level2.draw_line();
  glPopMatrix();

  // front left
  glPushMatrix();
  glTranslatef(-Width/2,0,Lenght/2);
  glRotatef(90,0,0,1);
  Level2.draw_line();
  glPopMatrix();

  // bottom right
  glPushMatrix();
  glTranslatef(Width/2,0,-Lenght/2);
  glRotatef(-90,0,0,1);
  Level2.draw_line();
  glPopMatrix();

  // bottom left
  glPushMatrix();
  glTranslatef(-Width/2,0,-Lenght/2);
  glRotatef(90,0,0,1);
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

/**
*
*@param
*@returns
*/

void _level3::draw_illumination_flat_shading()
{
  glMatrixMode(GL_MODELVIEW);
  // front right
  glPushMatrix();
  glTranslatef(Width/2,0,Lenght/2);
  glRotatef(-90,0,0,1);
  Level2.draw_illumination_flat_shading();
  glPopMatrix();

  // front left
  glPushMatrix();
  glTranslatef(-Width/2,0,Lenght/2);
  glRotatef(90,0,0,1);
  Level2.draw_illumination_flat_shading();
  glPopMatrix();

  // bottom right
  glPushMatrix();
  glTranslatef(Width/2,0,-Lenght/2);
  glRotatef(-90,0,0,1);
  Level2.draw_illumination_flat_shading();
  glPopMatrix();

  // bottom left
  glPushMatrix();
  glTranslatef(-Width/2,0,-Lenght/2);
  glRotatef(90,0,0,1);
  Level2.draw_illumination_flat_shading();
  glPopMatrix();
}

/**
*
*@param
*@returns
*/

void _level3::draw_illumination_smooth_shading()
{
  glMatrixMode(GL_MODELVIEW);
  // front right
  glPushMatrix();
  glTranslatef(Width/2,0,Lenght/2);
  glRotatef(-90,0,0,1);
  Level2.draw_illumination_smooth_shading();
  glPopMatrix();

  // front left
  glPushMatrix();
  glTranslatef(-Width/2,0,Lenght/2);
  glRotatef(90,0,0,1);
  Level2.draw_illumination_smooth_shading();
  glPopMatrix();

  // bottom right
  glPushMatrix();
  glTranslatef(Width/2,0,-Lenght/2);
  glRotatef(-90,0,0,1);
  Level2.draw_illumination_smooth_shading();
  glPopMatrix();

  // bottom left
  glPushMatrix();
  glTranslatef(-Width/2,0,-Lenght/2);
  glRotatef(90,0,0,1);
  Level2.draw_illumination_smooth_shading();
  glPopMatrix();
}

/**
*
*@param
*@returns
*/

void _level3::draw_texture()
{
  glMatrixMode(GL_MODELVIEW);
  // front right
  glPushMatrix();
  glTranslatef(Width/2,0,Lenght/2);
  glRotatef(-90,0,0,1);
//  Level2.draw_texture();
  glPopMatrix();

  // front left
  glPushMatrix();
  glTranslatef(-Width/2,0,Lenght/2);
  glRotatef(90,0,0,1);
  //Level2.draw_texture();
  glPopMatrix();

  // bottom right
  glPushMatrix();
  glTranslatef(Width/2,0,-Lenght/2);
  glRotatef(-90,0,0,1);
  //Level2.draw_texture();
  glPopMatrix();

  // bottom left
  glPushMatrix();
  glTranslatef(-Width/2,0,-Lenght/2);
  glRotatef(90,0,0,1);
  //Level2.draw_texture();
  glPopMatrix();
}

