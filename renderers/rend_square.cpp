#include "rend_square.h"

#include <math.h>
#include <qgl.h>

#include "particle.h"

Rend_Square::Rend_Square() :
  Renderer() {
}

Rend_Square::~Rend_Square() {
}

void Rend_Square::render(Particle *p) {
  glColor4f(p->color.r, p->color.g, p->color.b, p->color.a);
  glPushMatrix();
  glTranslatef(p->position.x, p->position.y, p->position.z);
  //@TODO: draw the mesh properly
  glBegin( GL_TRIANGLE_STRIP );
    glVertex3f(p->radius, p->radius, 0);
    glVertex3f(0 - p->radius, p->radius, 0);
    glVertex3f(p->radius, 0 - p->radius, 0);
    glVertex3f(0 - p->radius, 0 - p->radius, 0);
  glEnd( );
  glPopMatrix();
}
