QT += core gui opengl

RENDERERS = \
  pointrenderer

INITIALIZERS = \
  lifetimerandom \
  positionoffsetrandom \
  speedoffsetrandom \
  colorrandom

OPERATORS = \
  decay \
  basicphysics

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
  HEADERS += renderers/$${name}.h
  SOURCES += renderers/$${name}.cpp
}
for(name, INITIALIZERS) {
  HEADERS += initializers/$${name}.h
  SOURCES += initializers/$${name}.cpp
}
for(name, OPERATORS) {
  HEADERS += operators/$${name}.h
  SOURCES += operators/$${name}.cpp
}
