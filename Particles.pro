QT += core gui opengl

HEADERS += \
  particle.h \
  vector4d.h \
  window.h \
  glwidget.h \
  emitter.h \
  renderer.h \
  dummyrenderer.h \
  operator.h \
  initializer.h

SOURCES += \
  particle.cpp \
  vector4d.cpp \
  main.cpp \
  window.cpp \
  glwidget.cpp \
  emitter.cpp \
  dummyrenderer.cpp

OTHER_FILES += \
  README.md \
  LICENSE
