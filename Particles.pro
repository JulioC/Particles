QT += core gui opengl

RENDERERS = \
  point

INITIALIZERS = \
  lifetime \
  positionoffset \
  speedoffset \
  color \
  speed

OPERATORS = \
  decay \
  acceleration \
  drag

HEADERS += \
  particle.h \
  vector4d.h \
  window.h \
  glwidget.h \
  emitter.h \
  renderer.h \
  operator.h \
  initializer.h \
  timer.h

SOURCES += \
  particle.cpp \
  vector4d.cpp \
  main.cpp \
  window.cpp \
  glwidget.cpp \
  emitter.cpp \
  timer.cpp

RESOURCES += \
  resources.qrc

OTHER_FILES += \
  vshader.glsl \
  fshader.glsl \
  README.md \
  LICENSE

# Add  Renders, Initializers and Operators
for(name, RENDERERS) {
  HEADERS += renderers/rend_$${name}.h
  SOURCES += renderers/rend_$${name}.cpp
}
for(name, INITIALIZERS) {
  HEADERS += initializers/init_$${name}.h
  SOURCES += initializers/init_$${name}.cpp
}
for(name, OPERATORS) {
  HEADERS += operators/oper_$${name}.h
  SOURCES += operators/oper_$${name}.cpp
}
