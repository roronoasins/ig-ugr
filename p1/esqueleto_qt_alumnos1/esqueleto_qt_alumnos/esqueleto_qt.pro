HEADERS += \
  colors.h \
  basic_object3d.h \
  object3d.h \
  axis.h \
  tetrahedron.h \
  glwidget.h \
  window.h \
    cube.h

SOURCES += \
  basic_object3d.cc \
  object3d.cc \
  axis.cc \
  tetrahedron.cc \
  main.cc \
  glwidget.cc \
  window.cc \
    cube.cpp


LIBS += -L/usr/X11R6/lib64 -lGL


CONFIG += c++11
QT += widgets
