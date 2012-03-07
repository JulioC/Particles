#ifndef V3DGEN_LIST_H
#define V3DGEN_LIST_H

#include "v3dgenerator.h"

class V3DGen_List : public V3DGenerator {
public:
  V3DGen_List(const Vector3D *list, int length, bool random = true);
  virtual ~V3DGen_List();

  virtual Vector3D generate();

protected:
  Vector3D *_list;
  int _length;
  int _current;
  bool _random;
};

#endif // V3DGEN_LIST_H
