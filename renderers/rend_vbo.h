#ifndef REND_VBO_H
#define REND_VBO_H

#include "renderer.h"

#include "color.h"
#include "vector3d.h"

class QGLBuffer;
class QGLShaderProgram;

class Rend_VBO : public Renderer {
public:
  Rend_VBO(int maxVertex, QGLShaderProgram *_shaderProgram);
  virtual ~Rend_VBO();

  virtual void render(Particle *p);

  void clear();
  void draw();

  int vertexCount() { return _curVertex; }

protected:
  void vertex(const Vector3D &position, const Color &color);

  int _drawMode;

private:
  int _maxVertex;
  int _curVertex;

  QGLBuffer *_vboVertexes;
  QGLBuffer *_vboColors;

  QGLShaderProgram *_shaderProgram;
};

#endif // REND_VBO_H
