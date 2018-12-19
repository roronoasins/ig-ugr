HEADERS += \
  colors.h \
  basic_object3d.h \
  object3d.h \
  axis.h \
  tetrahedron.h \
  object3d_sweep_basic.h \
  level2.h \
  level3.h \
  glwidget.h \
  window.h \
    cube.h \
    cone.h \
    cylinder.h \
    sphere.h \
    object_ply.h \
    file_ply_stl.h \
    finger.h \
    palm.h \
    pyramid.h \
    hand.h \
    arm1.h \
    arm2.h \
    arm3.h \
    base.h

SOURCES += \
  basic_object3d.cc \
  object3d.cc \
  axis.cc \
  tetrahedron.cc \
  object3d_sweep_basic.cc \
  level2.cc \
  level3.cc \
  main.cc \
  glwidget.cc \
  window.cc \
    cube.cpp \
    cone.cpp \
    cylinder.cpp \
    sphere.cpp \
    object_ply.cpp \
    file_ply_stl.cpp \
    finger.cpp \
    palm.cpp \
    pyramid.cpp \
    hand.cpp \
    arm1.cpp \
    arm2.cpp \
    arm3.cpp \
    base.cpp


LIBS += -L/usr/X11R6/lib64 -lGL


CONFIG += c++11
QT += widgets
