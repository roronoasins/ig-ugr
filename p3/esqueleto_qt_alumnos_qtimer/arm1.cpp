#include "arm1.h"

void _arm1::create()
{
  Sphere.create(20, 0.4);
  Cylinder.create(20);
  _hand::create();
}

void _arm1::draw_line()
{
  glPushMatrix();
  glTranslatef(0,Sphere.radio,0);
  Sphere.draw_line();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(0,1.25+Sphere.radio*2,0);
  glScalef(0.5,2.5,0.5);
  Cylinder.draw_line();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(0,2.5+Sphere.radio*2,0);
  glRotatef(angle_hand,1,0,0);
  _hand::draw_line();
  glPopMatrix();
}

void _arm1::draw_point()
{
    glPushMatrix();
    glTranslatef(0,Sphere.radio,0);
    Sphere.draw_point();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,1.25+Sphere.radio*2,0);
    glScalef(0.5,2.5,0.5);
    Cylinder.draw_point();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,2.5+Sphere.radio*2,0);
    glRotatef(angle_hand,1,0,0);
    _hand::draw_point();
    glPopMatrix();
}

void _arm1::draw_fill()
{
    glPushMatrix();
    glTranslatef(0,Sphere.radio,0);
    Sphere.draw_fill();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,1.25+Sphere.radio*2,0);
    glScalef(0.5,2.5,0.5);
    Cylinder.draw_fill();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,2.5+Sphere.radio*2,0);
    glRotatef(angle_hand,1,0,0);
    _hand::draw_fill();
    glPopMatrix();
}

void _arm1::draw_chess()
{
    glPushMatrix();
    glTranslatef(0,Sphere.radio,0);
    Sphere.draw_chess();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,1.25+Sphere.radio*2,0);
    glScalef(0.5,2.5,0.5);
    Cylinder.draw_chess();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,2.5+Sphere.radio*2,0);
    glRotatef(angle_hand,1,0,0);
    _hand::draw_chess();
    glPopMatrix();
}

void _arm1::hand_forward()   {if(angle_hand<60)angle_hand+=speed_hand;}
void _arm1::hand_backward()  {if(angle_hand>-60) angle_hand-=speed_hand;}
void _arm1::increase_hand_speed()   {if(speed_hand<10)  speed_hand++;}
void _arm1::decrease_hand_speed()   {if(speed_hand>2)  speed_hand--;}
