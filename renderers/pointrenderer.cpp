#include "pointrenderer.h"

#include <qgl.h>

#include "particle.h"

PointRenderer::PointRenderer() :
  Renderer() {
}

PointRenderer::~PointRenderer() {
}

void PointRenderer::render(Particle *p) {
  glColor4ub(p->color[0], p->color[1], p->color[2], p->color[3]);
  glPushMatrix();
  glLoadIdentity();
  glTranslatef(p->position.x, p->position.y, p->position.z);
  glBegin(GL_POINTS);
    glVertex3f(0, 0, 0);
  glEnd();
  glPopMatrix();
}
