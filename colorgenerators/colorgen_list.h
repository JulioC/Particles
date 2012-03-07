#ifndef COLORGEN_LIST_H
#define COLORGEN_LIST_H

#include "colorgenerator.h"

class ColorGen_List : public ColorGenerator {
public:
  ColorGen_List(const Color *list, int length, bool random = true);
  virtual ~ColorGen_List();

  virtual Color generate();

protected:
  Color *_list;
  int _length;
  int _current;
  bool _random;
};

#endif // COLORGEN_LIST_H
