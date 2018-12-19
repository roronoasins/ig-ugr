#include "hand.h"

void _hand::create(float Height1, float Width1)
{
  Height=Height1;
  Width=Width1;

  Palm.create();
  F1.create();
  F2.create();
  F3.create();
  F4.create();
}

void _hand::open_hand()  {if(angle_fingers > 0) angle_fingers-=speed_fingers;}
void _hand::close_hand() {if(angle_fingers < 30) angle_fingers+=speed_fingers;}
void _hand::increase_fingers_speed()   {if(speed_fingers<10)  speed_fingers+=0.5;}
void _hand::decrease_fingers_speed()   {if(speed_fingers>0.5)  speed_fingers-=0.5;}


void _hand::draw_line()
{
  glMatrixMode(GL_MODELVIEW);
  glPushMatrix();
  Palm.draw_line();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(-Palm.getWidth()/2,Palm.getHeight()/2,Palm.getWidth()/2);
  glRotatef(-angle_fingers, 1,0,1);
  F1.draw_line();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(Palm.getWidth()/2,Palm.getHeight()/2,Palm.getWidth()/2);
  glRotatef(90,0,1,0);
  glRotatef(-angle_fingers, 1,0,1);
  F2.draw_line();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(-Palm.getWidth()/2,Palm.getHeight()/2,-Palm.getWidth()/2);
  glRotatef(-90,0,1,0);
  glRotatef(-angle_fingers,1,0,1);
  F3.draw_line();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(Palm.getWidth()/2,Palm.getHeight()/2,-Palm.getWidth()/2);
  glRotatef(angle_fingers, 1,0,1);
  F4.draw_line();
  glPopMatrix();
}

void _hand::draw_point()
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    Palm.draw_point();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-Palm.getWidth()/2,Palm.getHeight()/2,Palm.getWidth()/2);
    glRotatef(-angle_fingers, 1,0,1);
    F1.draw_point();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(Palm.getWidth()/2,Palm.getHeight()/2,Palm.getWidth()/2);
    glRotatef(90,0,1,0);
    glRotatef(-angle_fingers, 1,0,1);
    F2.draw_point();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-Palm.getWidth()/2,Palm.getHeight()/2,-Palm.getWidth()/2);
    glRotatef(-90,0,1,0);
    glRotatef(-angle_fingers,1,0,1);
    F3.draw_point();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(Palm.getWidth()/2,Palm.getHeight()/2,-Palm.getWidth()/2);
    glRotatef(angle_fingers, 1,0,1);
    F4.draw_point();
    glPopMatrix();
}

void _hand::draw_fill()
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    Palm.draw_fill();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-Palm.getWidth()/2,Palm.getHeight()/2,Palm.getWidth()/2);
    glRotatef(-angle_fingers, 1,0,1);
    F1.draw_fill();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(Palm.getWidth()/2,Palm.getHeight()/2,Palm.getWidth()/2);
    glRotatef(90,0,1,0);
    glRotatef(-angle_fingers, 1,0,1);
    F2.draw_fill();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-Palm.getWidth()/2,Palm.getHeight()/2,-Palm.getWidth()/2);
    glRotatef(-90,0,1,0);
    glRotatef(-angle_fingers,1,0,1);
    F3.draw_fill();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(Palm.getWidth()/2,Palm.getHeight()/2,-Palm.getWidth()/2);
    glRotatef(angle_fingers, 1,0,1);
    F4.draw_fill();
    glPopMatrix();
}

void _hand::draw_chess()
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    Palm.draw_chess();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-Palm.getWidth()/2,Palm.getHeight()/2,Palm.getWidth()/2);
    glRotatef(-angle_fingers, 1,0,1);
    F1.draw_chess();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(Palm.getWidth()/2,Palm.getHeight()/2,Palm.getWidth()/2);
    glRotatef(90,0,1,0);
    glRotatef(-angle_fingers, 1,0,1);
    F2.draw_chess();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-Palm.getWidth()/2,Palm.getHeight()/2,-Palm.getWidth()/2);
    glRotatef(-90,0,1,0);
    glRotatef(-angle_fingers,1,0,1);
    F3.draw_chess();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(Palm.getWidth()/2,Palm.getHeight()/2,-Palm.getWidth()/2);
    glRotatef(angle_fingers, 1,0,1);
    F4.draw_chess();
    glPopMatrix();
}
