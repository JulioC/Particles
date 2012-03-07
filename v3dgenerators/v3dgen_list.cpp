#include "v3dgen_list.h"

#include <stddef.h>

#include "random.h"

V3DGen_List::V3DGen_List(const Vector3D *list, int length, bool random) :
  V3DGenerator(),
  _list(NULL),
  _length(length),
  _current(0),
  _random(random) {
  _list = new Vector3D[_length];
  for(int i = 0; i < length; i++) {
    _list[i] = list[i];
  }
}

V3DGen_List::~V3DGen_List() {
  if(_list) {
    delete [] _list;
  }
}

Vector3D V3DGen_List::generate() {
  int i;

  if(_random) {
    i = Random::value(_length - 1);
  }
  else {
    i = _current;
    _current = (_current + 1) % _length;
  }

  return _list[i];
}
