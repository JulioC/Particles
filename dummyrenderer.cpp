#include "dummyrenderer.h"

#include <qgl.h>

#include "particle.h"

DummyRenderer::DummyRenderer() :
  Renderer() {
}

void DummyRenderer::render(Particle *p) {
  glColor4f(1.0, 1.0, 1.0, 1.0);
  glPushMatrix();
  glLoadIdentity();
  glTranslatef(p->position.x, p->position.y, p->position.z);
  glBegin(GL_POINTS);
    glVertex3f(0, 0, 0);
  glEnd();
  glPopMatrix();
}
