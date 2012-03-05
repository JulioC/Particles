#include "rend_sphere.h"

#include <math.h>
#include <qgl.h>

#include "particle.h"

Rend_Sphere::Rend_Sphere(int detailLevel) :
  Renderer(),
  _detailLevel(detailLevel) {
}

Rend_Sphere::~Rend_Sphere() {
}

void Rend_Sphere::render(Particle *p) {
  glColor4f(p->color.r, p->color.g, p->color.b, p->color.a);
  glPushMatrix();
  glTranslatef(p->position.x, p->position.y, p->position.z);
  //@TODO: draw the mesh properly
  drawSphere(p->radius, _detailLevel, _detailLevel);
  glPopMatrix();
}

void Rend_Sphere::drawSphere(float r, int lats, int longs) {
  for(int i = 0; i <= lats; i++) {
    float lat0 = M_PI * (-0.5 + (float) (i - 1) / lats);
    float z0  = r * sin(lat0);
    float zr0 =  r * cos(lat0);

    float lat1 = M_PI * (-0.5 + (float) i / lats);
    float z1 = r * sin(lat1);
    float zr1 = r * cos(lat1);

    glBegin(GL_QUAD_STRIP);
    for(int j = 0; j <= longs; j++) {
      float lng = 2 * M_PI * (float) (j - 1) / longs;
      float x = cos(lng);
      float y = sin(lng);
      glVertex3f(x * zr0, y * zr0, z0);
      glVertex3f(x * zr1, y * zr1, z1);
    }
    glEnd();
  }
}
