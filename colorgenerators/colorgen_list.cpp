#include "colorgen_list.h"

#include <stddef.h>

#include "random.h"

ColorGen_List::ColorGen_List(const Color *list, int length, bool random) :
  ColorGenerator(),
  _list(NULL),
  _length(length),
  _current(0),
  _random(random) {
}

ColorGen_List::~ColorGen_List() {
  if(_list) {
    delete [] _list;
  }
}

Color ColorGen_List::generate() {
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
