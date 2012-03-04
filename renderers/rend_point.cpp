#include "rend_point.h"

#include <qgl.h>

#include "particle.h"

Rend_Point::Rend_Point() :
  Renderer() {
}

Rend_Point::~Rend_Point() {
}

void Rend_Point::render(Particle *p) {
  glPointSize(p->radius);
  glColor4ub(p->color[0], p->color[1], p->color[2], p->color[3]);
  glPushMatrix();
  glTranslatef(p->position.x, p->position.y, p->position.z);
  glBegin(GL_POINTS);
    glVertex3f(0, 0, 0);
  glEnd();
  glPopMatrix();
}
