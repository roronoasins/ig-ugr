/*
* Prácticas de IG
* Copyright Domingo Martín Perandrés 2014-218
* dmartin@ugr.es
*
* GPL 3
*/

#include "glwidget.h"
#include "window.h"

using namespace std;
using namespace _gl_widget_ne;
using namespace _colors_ne;

/**
* Constructor
*
*@param
*@returns
*/

_gl_widget::_gl_widget(_window *Window1):Window(Window1)
{
  setMinimumSize(300, 300);
  setFocusPolicy(Qt::StrongFocus);
  Animation=false;
}

/**
* Evento tecla pulsada
*
*@param
*@returns
*/


void _gl_widget::keyPressEvent(QKeyEvent *Keyevent)
{
  switch(Keyevent->key()){
  case Qt::Key_1:Object=OBJECT_TETRAHEDRON;break;
  case Qt::Key_2:Object=OBJECT_CUBE;break;
  case Qt::Key_3:Object=OBJECT_CONE;break;
  case Qt::Key_4:Object=OBJECT_CYLINDER;break;
  case Qt::Key_5:Object=OBJECT_SPHERE;break;
  case Qt::Key_6:Object=OBJECT_PLY;break;
  case Qt::Key_7:Object=OBJECT_HIERARCHICAL;break;

  case Qt::Key_P:Draw_point=!Draw_point;break;
  case Qt::Key_L:Draw_line=!Draw_line;break;
  case Qt::Key_F:Draw_fill=!Draw_fill;break;
  case Qt::Key_C:Draw_chess=!Draw_chess;break;

  case Qt::Key_A:
    Animation=!Animation;
    set_arm_animation();
    break;

  case Qt::Key_E:
        Base.open_hand();
        actual = RETURN;
      break;
  case Qt::Key_R:
        Base.close_hand();
        actual = RETURN;
      break;
  case Qt::Key_Q:
        Base.hand_forward();
        actual = RETURN;
      break;
  case Qt::Key_W:
        Base.hand_backward();
        actual = RETURN;
      break;
  case Qt::Key_S:
        Base.lean_forward1();
        actual = RETURN;
      break;
  case Qt::Key_D:
        Base.lean_backward1();
        actual = RETURN;
      break;
  case Qt::Key_Z:
        Base.lean_forward2();
        actual = RETURN;
      break;
  case Qt::Key_X:
        Base.lean_backward2();
        actual = RETURN;
      break;
  case Qt::Key_N:
        Base.rotate_left();
        actual = RETURN;
      break;
  case Qt::Key_M:
        Base.rotate_right();
        actual = RETURN;
      break;
  case Qt::Key_T:
        Base.increase_fingers_speed();
      break;
  case Qt::Key_Y:
        Base.decrease_fingers_speed();
      break;
  case Qt::Key_U:
        Base.increase_hand_speed();
      break;
  case Qt::Key_I:
        Base.decrease_hand_speed();
      break;
  case Qt::Key_G:
        Base.increase_arm1_speed();
      break;
  case Qt::Key_H:
        Base.decrease_arm1_speed();
      break;
  case Qt::Key_J:
        Base.increase_arm2_speed();
      break;
  case Qt::Key_K:
        Base.decrease_arm2_speed();
      break;
  case Qt::Key_V:
        Base.increase_rotate_speed();
      break;
  case Qt::Key_B:
        Base.decrease_rotate_speed();
      break;

  case Qt::Key_Left:Observer_angle_y-=ANGLE_STEP;break;
  case Qt::Key_Right:Observer_angle_y+=ANGLE_STEP;break;
  case Qt::Key_Up:Observer_angle_x-=ANGLE_STEP;break;
  case Qt::Key_Down:Observer_angle_x+=ANGLE_STEP;break;
  case Qt::Key_PageUp:Observer_distance*=1.2;break;
  case Qt::Key_PageDown:Observer_distance/=1.2;break;
  }

  update();
}

/**
* Limpiar ventana
*
*@param
*@returns
*/

void _gl_widget::clear_window()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
}


/**
* Funcion para definir la transformación de proyeccion
*
*@param
*@returns
*/


void _gl_widget::change_projection()
{
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  // formato(x_minimo,x_maximo, y_minimo, y_maximo,Front_plane, plano_traser)
  //  Front_plane>0  Back_plane>PlanoDelantero)
  glFrustum(X_MIN,X_MAX,Y_MIN,Y_MAX,FRONT_PLANE_PERSPECTIVE,BACK_PLANE_PERSPECTIVE);
}


/**
* Funcion para definir la transformación de vista (posicionar la camara)
*
*@param
*@returns
*/

void _gl_widget::change_observer()
{
  // posicion del observador
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glTranslatef(0,0,-Observer_distance);
  glRotatef(Observer_angle_x,1,0,0);
  glRotatef(Observer_angle_y,0,1,0);
}


/**
* Funcion que dibuja los objetos
*
*@param
*@returns
*/

void _gl_widget::draw_objects()
{
  Axis.draw_line();

  if (Draw_point){
    glPointSize(5);
    glColor3fv((GLfloat *) &BLACK);
    switch (Object){
    case OBJECT_CUBE:Cube.draw_point();break;
    case OBJECT_TETRAHEDRON:Tetrahedron.draw_point();break;
    case OBJECT_CONE:Cone.draw_point();break;
    case OBJECT_CYLINDER:Cylinder.draw_point();break;
    case OBJECT_SPHERE:Sphere.draw_point();break;
    case OBJECT_PLY:Object_ply.draw_point();break;
    case OBJECT_HIERARCHICAL:Base.draw_point();break;
    default:break;
    }
  }

  if (Draw_line){
    glLineWidth(1);
    glColor3fv((GLfloat *) &MAGENTA);
    switch (Object){
    case OBJECT_CUBE:Cube.draw_line();break;
    case OBJECT_TETRAHEDRON:Tetrahedron.draw_line();break;
    case OBJECT_CONE:Cone.draw_line();break;
    case OBJECT_CYLINDER:Cylinder.draw_line();break;
    case OBJECT_SPHERE:Sphere.draw_line();break;
    case OBJECT_PLY:Object_ply.draw_line();break;
    case OBJECT_HIERARCHICAL:Base.draw_line();break;
    default:break;
    }
  }

  if (Draw_fill){
    glColor3fv((GLfloat *) &BLUE);
    switch (Object){
    case OBJECT_CUBE:Cube.draw_fill();break;
    case OBJECT_TETRAHEDRON:Tetrahedron.draw_fill();break;
    case OBJECT_CONE:Cone.draw_fill();break;
    case OBJECT_CYLINDER:Cylinder.draw_fill();break;
    case OBJECT_SPHERE:Sphere.draw_fill();break;
    case OBJECT_PLY:Object_ply.draw_fill();break;
    case OBJECT_HIERARCHICAL:Base.draw_fill();break;
    default:break;
    }
  }

  if (Draw_chess){
    switch (Object){
    case OBJECT_CUBE:Cube.draw_chess();break;
    case OBJECT_TETRAHEDRON:Tetrahedron.draw_chess();break;
    case OBJECT_CONE:Cone.draw_chess();break;
    case OBJECT_CYLINDER:Cylinder.draw_chess();break;
    case OBJECT_SPHERE:Sphere.draw_chess();break;
    case OBJECT_PLY:Object_ply.draw_chess();break;
    case OBJECT_HIERARCHICAL:Base.draw_chess();break;
    default:break;
    }
  }
}


/**
* Evento de dibujado
*
*@param
*@returns
*/


void _gl_widget::paintGL()
{
  clear_window();
  change_projection();
  change_observer();
  draw_objects();
}


/**
* Evento de cambio de tamaño de la ventana
*@param
*@returns
*/

void _gl_widget::resizeGL(int Width1, int Height1)
{
  glViewport(0,0,Width1,Height1);
}


/**
* Inicialización de OpenGL
*@param
*@returns
*/

void _gl_widget::initializeGL()
{
  const GLubyte* strm;

  strm = glGetString(GL_VENDOR);
  std::cerr << "Vendor: " << strm << "\n";
  strm = glGetString(GL_RENDERER);
  std::cerr << "Renderer: " << strm << "\n";
  strm = glGetString(GL_VERSION);
  std::cerr << "OpenGL Version: " << strm << "\n";

  if (strm[0] == '1'){
    std::cerr << "Only OpenGL 1.X supported!\n";
    exit(-1);
  }

  strm = glGetString(GL_SHADING_LANGUAGE_VERSION);
  std::cerr << "GLSL Version: " << strm << "\n";

  int Max_texture_size=0;
  glGetIntegerv(GL_MAX_TEXTURE_SIZE, &Max_texture_size);
  std::cerr << "Max texture size: " << Max_texture_size << "\n";

  glClearColor(1.0,1.0,1.0,1.0);
  glEnable(GL_DEPTH_TEST);;

  Observer_angle_x=0;
  Observer_angle_y=0;
  Observer_distance=DEFAULT_DISTANCE;

  Draw_point=false;
  Draw_line=true;
  Draw_fill=false;
  Draw_chess=false;

  Animation=false;

  Base.create();
  Level3.create();
  Cone.create(40);
  Cylinder.create(40);
  Sphere.create(45,0.8);


  _file_ply File;
  vector<float> Coordinates;
  vector<unsigned int> Positions;

  File.open("/home/luis/Documentos/3/1/ig/p3/esqueleto_qt_alumnos2/esqueleto_qt_alumnos/ply/beethoven.ply");
  File.read(Coordinates,Positions);
  Object_ply.create(Coordinates,Positions);
  File.close();

  Timer = new QTimer(this);
  connect(Timer, SIGNAL(timeout()), this, SLOT(tick()));
}

/**
* Activa/Desactiva Animación
*@param
*@returns
*/

void _gl_widget::set_arm_animation()
{
    if (Animation){
        Timer->start(100);
    }
    else {
        Timer->stop();
        delete Timer;
        Timer = new QTimer(this);
    }

    }

/**
* Función para el QTimer(Animación)
*@param
*@returns
*/

void _gl_widget::tick()
{


  switch (actual) {
    case REPOSO:
      actual = (actual == REPOSO && last == REPOSO) ? BAJAR_ARM2 : REPOSO;
      break;
    case GIRO_IDA:
      if (Base.angle_rotate < 45)
        Base.rotate_left();
      else {actual = BAJAR_ARM1;last=GIRO_IDA;}
      break;
    case BAJAR_ARM2:
      if (Base.angle_arm2 < 40)
        Base.lean_forward2();
      else actual = GIRO_IDA;
      break;
    case BAJAR_ARM1:
      if (Base.angle_arm1 < 60)
        Base.lean_forward1();
      else {
          if (last == TURN_RIGHT)
            actual = OPEN_HAND;
          else if (last == GIRO_IDA) actual = BAJAR_HAND;
      }
      break;
    case BAJAR_HAND:
      if (Base.angle_hand < 20)
        Base.hand_forward();
      else actual = CLOSE_HAND;
      break;
    case CLOSE_HAND:
      if (Base.angle_fingers < 25)
        Base.close_hand();
      else actual = SUBIR_ARM1;
      break;
    case SUBIR_ARM1:
      if (Base.angle_arm1 < 25)
        Base.lean_backward1();
      else actual = TURN_RIGHT;
      break;
    case TURN_RIGHT:
      if (Base.angle_rotate > -65)
        Base.rotate_right();
      else {actual = BAJAR_ARM1;last=TURN_RIGHT;}
      break;
    case OPEN_HAND:
      if (Base.angle_fingers > 0)
        Base.open_hand();
      else actual = RETURN;
      break;
    case RETURN:
        if (Base.angle_rotate < 0)
            Base.rotate_left();
        else if (Base.angle_arm2 > 0)
            Base.lean_backward2();
        else if (Base.angle_arm1 < 0)
            Base.lean_backward1();
        else if (Base.angle_hand > 0)
            Base.hand_backward();
        else {actual = REPOSO;last=REPOSO;}
        break;
  }
  update();

}
