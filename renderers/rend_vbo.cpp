#include "rend_vbo.h"

#include <math.h>

#include <qgl.h>

#include <QVector4D>
#include <QGLBuffer>
#include <QGLShaderProgram>

#include "particle.h"
#include "vector3d.h"

Rend_VBO::Rend_VBO(int maxVertex, QGLShaderProgram *shaderProgram) :
  Renderer(),
  _maxVertex(maxVertex),
  _curVertex(0),
  _drawMode(GL_POINTS),
  _shaderProgram(shaderProgram) {

  _vboVertexes = new QGLBuffer(QGLBuffer::VertexBuffer);
  _vboVertexes->create();
  _vboVertexes->bind();
  _vboVertexes->setUsagePattern(QGLBuffer::DynamicDraw);
  _vboVertexes->allocate(NULL, _maxVertex * sizeof(Vector3D));

  _vboColors = new QGLBuffer(QGLBuffer::VertexBuffer);
  _vboColors->create();
  _vboColors->bind();
  _vboColors->setUsagePattern(QGLBuffer::DynamicDraw);
  _vboColors->allocate(NULL, _maxVertex * sizeof(Color));
}

Rend_VBO::~Rend_VBO() {
}

void Rend_VBO::render(Particle *p) {
  vertex(p->position, p->color);
}

void Rend_VBO::clear() {
  _curVertex = 0;
}

void Rend_VBO::draw() {
  _vboVertexes->bind();
  _shaderProgram->enableAttributeArray("vPosition");
  _shaderProgram->setAttributeBuffer("vPosition", GL_FLOAT, 0, 3, 0);

  _vboColors->bind();
  _shaderProgram->enableAttributeArray("vColor");
  _shaderProgram->setAttributeBuffer("vColor", GL_FLOAT, 0, 4, 0);

  glDrawArrays(_drawMode, 0, _curVertex);
}

void Rend_VBO::vertex(const Vector3D &position, const Color &color) {
  if(_curVertex < _maxVertex) {
    int i = _curVertex++;

    _vboVertexes->bind();
    Vector3D* vertexes = (Vector3D*) _vboVertexes->map(QGLBuffer::WriteOnly);
    vertexes[i] = position;
    _vboVertexes->unmap();

    _vboColors->bind();
    Color* colors = (Color*) _vboColors->map(QGLBuffer::WriteOnly);
    colors[i] = color;
    _vboColors->unmap();
  }
}
