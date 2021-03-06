QT += core gui opengl

RENDERERS = \
  point \
  sphere \
  square \
  vbo

INITIALIZERS = \
  lifetime \
  speedoffset \
  color \
  speed \
  radius \
  direction \
  position

OPERATORS = \
  decay \
  acceleration \
  drag \
  fade

V3DGENERATORS = \
  cone \
  sphere \
  box \
  point \
  cylinder \
  list

COLORGENERATORS = \
  constant \
  range \
  list

HEADERS += \
  particle.h \
  vector3d.h \
  window.h \
  glwidget.h \
  emitter.h \
  renderer.h \
  operator.h \
  initializer.h \
  timer.h \
  color.h \
  camera.h \
  camerashader.h \
  random.h \
  v3dgenerator.h \
  colorgenerator.h \
  testbed.h \
  emitterspanel.h \
    emittercontroller.h

SOURCES += \
  particle.cpp \
  vector3d.cpp \
  main.cpp \
  window.cpp \
  glwidget.cpp \
  emitter.cpp \
  timer.cpp \
  color.cpp \
  camera.cpp \
  camerashader.cpp \
  random.cpp \
  testbed.cpp \
  emitterspanel.cpp \
    emittercontroller.cpp

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
for(name, V3DGENERATORS) {
  HEADERS += v3dgenerators/v3dgen_$${name}.h
  SOURCES += v3dgenerators/v3dgen_$${name}.cpp
}
for(name, COLORGENERATORS) {
  HEADERS += colorgenerators/colorgen_$${name}.h
  SOURCES += colorgenerators/colorgen_$${name}.cpp
}

FORMS += \
  testbed.ui \
  emitterspanel.ui \
    emittercontroller.ui
