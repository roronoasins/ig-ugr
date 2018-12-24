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
#include <QImage>
#include<QImageReader>

#include <iostream>
#include "vertex.h"
#include "colors.h"
#include "axis.h"
#include "tetrahedron.h"

namespace _gl_widget_ne {
  const float X_MAX=.1;
  const float FRONT_PLANE_PARALLEL=-5000;
  const float BACK_PLANE_PARALLEL=5000;
  const float FRONT_PLANE_PERSPECTIVE=X_MAX;
  const float BACK_PLANE_PERSPECTIVE=1000;
  const float DEFAULT_DISTANCE=4;
  const float DISTANCE_FACTOR=1.1;
  const float ANGLE_STEP_KEY=1;
  const float ANGLE_STEP_MOUSE=.1;
  const float DEFAULT_SCALE_FACTOR=16;

  typedef enum {MODE_DRAW_POINT,MODE_DRAW_LINE,MODE_DRAW_FILL} _mode_draw;
  typedef enum {MODE_RENDERING_SOLID,MODE_RENDERING_SOLID_CHESS, MODE_RENDERING_ILLUMINATION_FLAT_SHADING, MODE_RENDERING_ILLUMINATION_SMOOTH_SHADING, MODE_RENDERING_TEXTURE} _mode_rendering;
  typedef enum {OBJECT_TETRAHEDRON} _object;

  typedef enum {PERSPECTIVE_PROJECTION,PARALLEL_PROJECTION} _projection_type;

  const float INC_LIGHT1_ANGLE=0.01;
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

  void set_animation();

  void pick();

protected:
  void resizeGL(int Width1, int Height1) Q_DECL_OVERRIDE;
  void paintGL() Q_DECL_OVERRIDE;
  void initializeGL() Q_DECL_OVERRIDE;
  void keyPressEvent(QKeyEvent *Keyevent) Q_DECL_OVERRIDE;
  void mousePressEvent(QMouseEvent *Event) Q_DECL_OVERRIDE;
  void mouseReleaseEvent(QMouseEvent *Event) Q_DECL_OVERRIDE;
  void mouseMoveEvent(QMouseEvent *Event) Q_DECL_OVERRIDE;
  void wheelEvent(QWheelEvent *Event) Q_DECL_OVERRIDE;


protected slots:
  void tick();

private:
  _window *Window;

  _axis Axis;
  _tetrahedron Tetrahedron;

  _gl_widget_ne::_object Object;

  bool Draw_point;
  bool Draw_line;
  bool Draw_fill;
  bool Draw_chess;

  _gl_widget_ne::_mode_rendering Mode_rendering;

  float Observer_angle_x;
  float Observer_angle_y;
  float Observer_distance;

  int last_x;
  int last_y;

  bool Animation;

  QTimer *Timer;

  int Window_width;
  int Window_height;

  int Initial_position_x;
  int Initial_position_y;
  bool Change_position;
  bool Change_camera;

  bool Show_selection;
  int Selection_position_x;
  int Selection_position_y;

  GLuint FBO;
  GLuint Color_texture;
  GLuint Depth_texture;

  int Selected_triangle;

  float Camera_width;

  _gl_widget_ne::_projection_type Projection_type;
  float Scale_factor;
};

#endif
