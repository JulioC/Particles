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
  glColor4f(p->color.r, p->color.g, p->color.b, p->color.a);
  glPushMatrix();
  glTranslatef(p->position.x, p->position.y, p->position.z);
  glBegin(GL_POINTS);
    glVertex3f(0, 0, 0);
  glEnd();
  glPopMatrix();
}
