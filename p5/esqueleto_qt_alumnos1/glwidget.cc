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
  case Qt::Key_2:Object=OBJECT_PLY;break;
  case Qt::Key_3:break;
  case Qt::Key_4:break;
  case Qt::Key_5:break;
  case Qt::Key_6:break;
  case Qt::Key_7:break;
  case Qt::Key_8:break;

  case Qt::Key_P:Draw_point=!Draw_point;break;
  case Qt::Key_L:Draw_line=!Draw_line;break;
  case Qt::Key_F:Draw_fill=!Draw_fill;break;

  case Qt::Key_F1:Mode_rendering=MODE_RENDERING_SOLID;break;
  case Qt::Key_F2:break;
  case Qt::Key_F3:break;
  case Qt::Key_F4:break;
  case Qt::Key_F5:break;

  case Qt::Key_A:
    Animation=!Animation;
    set_animation();
    break;

  case Qt::Key_J:break;
  case Qt::Key_K:break;

  case Qt::Key_M:break;
  case Qt::Key_Left:Observer_angle_y-=ANGLE_STEP_KEY;break;
  case Qt::Key_Right:Observer_angle_y+=ANGLE_STEP_KEY;break;
  case Qt::Key_Up:Observer_angle_x-=ANGLE_STEP_KEY;break;
  case Qt::Key_Down:Observer_angle_x+=ANGLE_STEP_KEY;break;

  /*************************/
  case Qt::Key_PageUp:
    if (Projection_type==PERSPECTIVE_PROJECTION) Observer_distance*=DISTANCE_FACTOR;
    else{
      /*************************/

      /*************************/
    }
    break;
  case Qt::Key_PageDown:
    if (Projection_type==PERSPECTIVE_PROJECTION) Observer_distance/=DISTANCE_FACTOR;
    else{
      /*************************/

      /*************************/
    }
    break;
  /*************************/

  case Qt::Key_Q:break;
  case Qt::Key_W:break;
  case Qt::Key_S:Draw_selection=!Draw_selection;break;
  case Qt::Key_D:break;
  case Qt::Key_Z:break;
  case Qt::Key_X:break;

  case Qt::Key_E:break;
  case Qt::Key_R:break;
  case Qt::Key_T:break;
  case Qt::Key_Y:break;
  case Qt::Key_U:break;
  case Qt::Key_I:break;

  case Qt::Key_C:Projection_type=PERSPECTIVE_PROJECTION;break;
  case Qt::Key_V:Projection_type=PARALLEL_PROJECTION;break;
  }

  update();
}

/**
*
*@param
*@returns
*/

void _gl_widget::mousePressEvent(QMouseEvent *Event)
{
  /*************************/

    /*if ( Event->buttons ( ) & Qt::LeftButton ) {
        Change_position=true ;
        Initial_position_x = Event->x();
        Initial_position_y = Event->y();
    }
    else */
    if ( Event->buttons() & Qt::RightButton ) {
        Selection_position_x = Event->x();
        Selection_position_y = height() - Event->y();
    }

  /*************************/
}

/**
*
*@param
*@returns
*/

void _gl_widget::mouseReleaseEvent(QMouseEvent *Event)
{
  /*************************/

    if (Draw_fill) {
        if ( Event->button() & Qt::RightButton ) {
            cout << "pick" << endl;
            pick();
            update();
        }
    }

  /*************************/


}


/**
*
*@param
*@returns
*/

void _gl_widget::mouseMoveEvent(QMouseEvent *Event)
{
   int x = Event->x(), y = Event->y();

    if ( Event->buttons() & Qt::LeftButton ) {
        if ( last_x < x )   Observer_angle_y+=ANGLE_STEP_KEY/3;
        else if (last_x > x )   Observer_angle_y-=ANGLE_STEP_KEY/3;
        if ( last_y < y )   Observer_angle_x+=ANGLE_STEP_KEY/3;
        else if (last_y > y )   Observer_angle_x-=ANGLE_STEP_KEY/3;

        last_x = x;
        last_y = y;
    }
    update();
}

/**
*
*@param
*@returns
*/

void _gl_widget::wheelEvent(QWheelEvent *Event)
{
    //Most mouse types work in steps of 15 degrees, in which case the delta value is a multiple of 120; i.e., 120 units * 1/8 = 15 degrees.

    const int degrees = Event->delta()  / 8;
    int steps = degrees / 15;
    //cout << degrees << " " << steps << endl;

    if (Projection_type==PERSPECTIVE_PROJECTION) {
        if (degrees > 0) Observer_distance /= steps*DISTANCE_FACTOR;
        else if (degrees < 0)  Observer_distance *= abs(steps*DISTANCE_FACTOR);
    }else if (Projection_type==PARALLEL_PROJECTION) {
            if (degrees > 0) Observer_distance /= steps*DISTANCE_FACTOR*DEFAULT_SCALE_FACTOR;
            else if (degrees < 0)  Observer_distance *= abs(steps*DISTANCE_FACTOR*DEFAULT_SCALE_FACTOR);
            }

    Event->accept();
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

  float Aspect=(float)Window_height/(float)Window_width;


  /*************************/

  if (Projection_type==PERSPECTIVE_PROJECTION){
    glFrustum(-Camera_width,Camera_width,-Camera_width*Aspect, Camera_width*Aspect,FRONT_PLANE_PERSPECTIVE,BACK_PLANE_PERSPECTIVE);
  }
  else if (Projection_type==PARALLEL_PROJECTION){
      glOrtho(-Camera_width*DEFAULT_SCALE_FACTOR , X_MAX*DEFAULT_SCALE_FACTOR , -Camera_width*Aspect*DEFAULT_SCALE_FACTOR , Camera_width*Aspect*DEFAULT_SCALE_FACTOR , FRONT_PLANE_PARALLEL , BACK_PLANE_PARALLEL );

  /*************************/
  }
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
    case OBJECT_TETRAHEDRON:Tetrahedron.draw_point();break;
    case OBJECT_PLY:Ply.draw_point();break;
    default:break;
    }
  }

  if (Draw_line){
    glLineWidth(1);
    glColor3fv((GLfloat *) &MAGENTA);
    switch (Object){
    case OBJECT_TETRAHEDRON:Tetrahedron.draw_line();break;
    case OBJECT_PLY:Ply.draw_line();break;
    default:break;
    }
  }

  if (Draw_fill){
    switch (Mode_rendering){
    case MODE_RENDERING_SOLID:
      //glColor3fv((GLfloat *) &BLUE);
      switch (Object){
      case OBJECT_TETRAHEDRON:Tetrahedron.draw_fill();break;
      case OBJECT_PLY:Ply.draw_fill();break;
      default:break;
      }
      break;
    default:break;
    }
  }

if (Draw_selection){
  switch (Mode_rendering){
  case MODE_RENDERING_SOLID:
    switch (Object){
    case OBJECT_TETRAHEDRON:Tetrahedron.draw_selection();break;
    case OBJECT_PLY:Ply.draw_selection();break;
    default:break;
    }
    break;
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
  Window_width=Width1;
  Window_height=Height1;

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

  glewExperimental = GL_TRUE;
  int err = glewInit();
  if (GLEW_OK != err){
    std::cerr << "Error: " << glewGetErrorString(err) << "\n";
    exit (-1);
  }

  int Max_texture_size=0;
  glGetIntegerv(GL_MAX_TEXTURE_SIZE, &Max_texture_size);
  std::cerr << "Max texture size: " << Max_texture_size << "\n";

  glClearColor(1.0,1.0,1.0,1.0);
  glEnable(GL_DEPTH_TEST);;

  Window_width=width();
  Window_height=height();

  Change_camera=true;
  Observer_angle_x=0;
  Observer_angle_y=0;
  Observer_distance=DEFAULT_DISTANCE;
  Show_selection=false;
  Selected_triangle=-1;

  Camera_width=X_MAX;

  Draw_point=false;
  Draw_line=true;
  Draw_fill=false;
  Draw_chess=false;
  Draw_selection=false;

  Animation=false;


  Timer = new QTimer(this);
  Timer->setInterval(0);
  connect(Timer, SIGNAL(timeout()), this, SLOT(tick()));


  Object=OBJECT_TETRAHEDRON;
  Mode_rendering=MODE_RENDERING_SOLID;

  /*************************/

  _file_ply File;
  vector<float> Coordinates;
  vector<unsigned int> Positions;

  File.open("/home/luis/Documentos/3/1/ig/ig-ugr/p5/esqueleto_qt_alumnos1/ply/beethoven.ply");
  File.read(Coordinates,Positions);
  Ply.create(Coordinates,Positions);
  File.close();

  last_x=0;
  last_y=0;

  /*************************/

}

/**
*
*@param
*@returns
*/

void _gl_widget::set_animation()
{
  if (Animation) Timer->start();
  else Timer->stop();
}

/**
*
*@param
*@returns
*/

void _gl_widget::tick()
{
  cout << "Tic" << endl;

  update();
}


/**
*
*@param
*@returns
*/

void _gl_widget::pick()
{
    /*
     * Para poder seleccionar las partes del objeto con identificadores únicos se hará obteniendo un píxel del triángulo a seleccionar
     * y pasando de RGB a entero.
     *
     * Para que eso sea posible dibujamos el objeto en un framebuffer distinto al que usamos para dibujar normalmente y se asigna a cada triángulo
     * según el orden de dibujado sus componentes RGB(int -> RGB)
     *
     * Al hacer pick en un triángulo, se extrae un píxel y obtenemos el identificador único asociado(RGB -> int) de la selección sin tener que mostrar por pantalla el dibujado de los triángulos por tonalidades.
     *
     * Para ello: dibujamos los triángulos modificando el color con la posición
     * se dibuja el objeto (en un framebuffer distinto al que usamos para dibujar en la ventana)
     * para poder calcular los identificadores de cada parte del objeto haciendo uso de las componentes RGB
     *
     * */

    makeCurrent();

    // Frame Buffer Object to do the off-screen rendering
    glGenFramebuffers(1,&FBO);
    glBindFramebuffer(GL_FRAMEBUFFER,FBO);

    // Texture for drawing
    glGenTextures(1,&Color_texture);
    glBindTexture(GL_TEXTURE_2D,Color_texture);
    // RGBA8
    glTexStorage2D(GL_TEXTURE_2D,1,GL_RGBA8, Window_width,Window_height);
    // this implies that there is not mip mapping
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);

    // Texure for computing the depth
    glGenTextures(1,&Depth_texture);
    glBindTexture(GL_TEXTURE_2D,Depth_texture);
    // Float
    glTexStorage2D(GL_TEXTURE_2D,1,GL_DEPTH_COMPONENT24, Window_width,Window_height);

    // Attatchment of the textures to the FBO
    glFramebufferTexture(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0,Color_texture,0);
    glFramebufferTexture(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT,Depth_texture,0);

    // OpenGL will draw to these buffers (only one in this case)
    static const GLenum Draw_buffers[]={GL_COLOR_ATTACHMENT0};
    glDrawBuffers(1,Draw_buffers);

    /*************************/

    switch (Object){
        case OBJECT_TETRAHEDRON:Tetrahedron.draw_selection();break;
        case OBJECT_PLY:Ply.draw_selection();break;
    default:break;
    }

    /*************************/

    // get the pixel
    int Color;
    glReadBuffer(GL_FRONT);
    glPixelStorei(GL_PACK_ALIGNMENT,1);
    glReadPixels(Selection_position_x,Selection_position_y,1,1,GL_RGBA,GL_UNSIGNED_BYTE,&Color);

    /*************************/

    uint B=uint ( ( Color & 0x00FF0000 ) >> 16 ) ;
    uint G=uint ( ( Color & 0x0000FF00 ) >> 8 ) ;
    uint R=uint ( ( Color & 0x000000FF ) ) ;

    // RGB -> identifier
    Selected_triangle = ( R << 16 ) + ( G << 8 ) + B ;
    if ( Selected_triangle==16777215) Selected_triangle = -1;

    switch (Object){
        case OBJECT_TETRAHEDRON:Tetrahedron.selected_triangle(Selected_triangle);break;
        case OBJECT_PLY:Ply.selected_triangle(Selected_triangle);break;
    default:break;
    }
    /*************************/

    glDeleteTextures(1,&Color_texture);
    glDeleteTextures(1,&Depth_texture);
    glDeleteFramebuffers(1,&FBO);
    // the normal framebuffer takes the control of drawing
    glBindFramebuffer(GL_DRAW_FRAMEBUFFER,defaultFramebufferObject());
}

