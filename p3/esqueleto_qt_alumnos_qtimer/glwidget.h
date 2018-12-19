/*
* Prácticas de IG
* Copyright Domingo Martín Perandrés 2014-218
* dmartin@ugr.es
*
* GPL 3
*/

#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <GL/glew.h>
#include <QOpenGLWidget>
#include <QKeyEvent>
#include <QTimer>

#include <iostream>
#include "vertex.h"
#include "colors.h"
#include "axis.h"
#include "cube.h"
#include "tetrahedron.h"
#include "cone.h"
#include "cylinder.h"
#include "sphere.h"
#include "object_ply.h"
#include "file_ply_stl.h"
#include "level2.h"
#include "level3.h"

#include "base.h"


namespace _gl_widget_ne {

  const float X_MIN=-.1;
  const float X_MAX=.1;
  const float Y_MIN=-.1;
  const float Y_MAX=.1;
  const float FRONT_PLANE_PERSPECTIVE=(X_MAX-X_MIN)/2;
  const float BACK_PLANE_PERSPECTIVE=1000;
  const float DEFAULT_DISTANCE=4;
  const float ANGLE_STEP=1;

  typedef enum {MODE_DRAW_POINT,MODE_DRAW_LINE,MODE_DRAW_FILL,MODE_DRAW_CHESS} _mode_draw;
  typedef enum {OBJECT_TETRAHEDRON,OBJECT_CUBE,OBJECT_CONE,OBJECT_CYLINDER,OBJECT_SPHERE,OBJECT_PLY,OBJECT_HIERARCHICAL,OBJECT_PYRAMID} _object;
}


class _window;

class _gl_widget : public QOpenGLWidget
{
Q_OBJECT

public:
  _gl_widget(_window *Window1);

  void clear_window();
  void change_projection();
  void change_observer();

  void draw_axis();
  void draw_objects();

  void set_arm_animation();

protected:
  void resizeGL(int Width1, int Height1) Q_DECL_OVERRIDE;
  void paintGL() Q_DECL_OVERRIDE;
  void initializeGL() Q_DECL_OVERRIDE;
  void keyPressEvent(QKeyEvent *Keyevent) Q_DECL_OVERRIDE;

protected slots:
  void tick();

private:
  _window *Window;

  _axis Axis;
  _tetrahedron Tetrahedron;
  _cube Cube;
  _cone Cone;
  _cylinder Cylinder;
  _sphere Sphere;
  _object_ply Object_ply;
  _level3 Level3;
  _level2 Level2;
  _base Base;

  _gl_widget_ne::_object Object;

  bool Draw_point;
  bool Draw_line;
  bool Draw_fill;
  bool Draw_chess;

  enum State {
      REPOSO, GIRO_IDA, BAJAR_ARM2, BAJAR_ARM1, BAJAR_HAND, CLOSE_HAND,
      OPEN_HAND, SUBIR_ARM1, TURN_RIGHT, RETURN
  };State actual = REPOSO, last=REPOSO;

  float Observer_angle_x;
  float Observer_angle_y;
  float Observer_distance;

  bool Animation;

  QTimer *Timer;
};

#endif
