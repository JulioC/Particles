QT += core gui opengl

RENDERERS = dummy
INITIALIZERS =
OPERATORS = decay

HEADERS += \
  particle.h \
  vector4d.h \
  window.h \
  glwidget.h \
  emitter.h \
  renderer.h \
  operator.h \
  initializer.h

SOURCES += \
  particle.cpp \
  vector4d.cpp \
  main.cpp \
  window.cpp \
  glwidget.cpp \
  emitter.cpp

OTHER_FILES += \
  README.md \
  LICENSE

# Add  Renders, Initializers and Operators
for(name, RENDERERS) {
  HEADERS += renderers/$${name}renderer.h
  SOURCES += renderers/$${name}renderer.cpp
}
for(name, INITIALIZER) {
  HEADERS += initializers/$${name}initializer.h
  SOURCES += initializers/$${name}initializer.cpp
}
for(name, OPERATORS) {
  HEADERS += operators/$${name}operator.h
  SOURCES += operators/$${name}operator.cpp
}