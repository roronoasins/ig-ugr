HEADERS += \
  colors.h \
  basic_object3d.h \
  object3d.h \
  axis.h \
  tetrahedron.h \
  glwidget.h \
  window.h \
    object3d_sweep_basic.h \
    file_ply.h \
    object_ply.h \
    object_ply.h

SOURCES += \
  basic_object3d.cc \
  object3d.cc \
  axis.cc \
  tetrahedron.cc \
  main.cc \
  glwidget.cc \
  window.cc \
    object3d_sweep_basic.cpp \
    file_ply.cpp \
    object_ply.cpp


INCLUDEPATH += /casa/dmartin/codigo/funciontecas/glew/include

LIBS += -L/usr/X11R6/lib64 -lGL \
        -L/casa/dmartin/codigo/funciontecas/glew/lib -lGLEW


CONFIG += c++11
QT += widgets
