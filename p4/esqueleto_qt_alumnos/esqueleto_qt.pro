HEADERS += \
  colors.h \
  basic_object3d.h \
  object3d.h \
  axis.h \
  tetrahedron.h \
  object3d_sweep_basic.h \
  cone.h \
  cylinder.h \
  sphere.h \
  file_ply_stl.h \
  object_ply.h \
  level2.h \
  level3.h \
  chess_board.h \
  glwidget.h \
  window.h \
    cube.h \
    arm1.h \
    arm2.h \
    arm3.h \
    base.h \
    finger.h \
    pyramid.h \
    hand.h \
    palm.h

SOURCES += \
  basic_object3d.cc \
  object3d.cc \
  axis.cc \
  tetrahedron.cc \
  object3d_sweep_basic.cc \
  cone.cc \
  cylinder.cc \
  sphere.cc \
  file_ply_stl.cc \
  object_ply.cc \
  level2.cc \
  level3.cc \
  chess_board.cc \
  main.cc \
  glwidget.cc \
  window.cc \
    cube.cpp \
    arm1.cpp \
    arm2.cpp \
    arm3.cpp \
    base.cpp \
    finger.cpp \
    pyramid.cpp \
    hand.cpp \
    palm.cpp


LIBS += -L/usr/X11R6/lib64 -lGL


CONFIG += c++11
QT += widgets
