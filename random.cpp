#include "random.h"

#include <stdlib.h>
#include <time.h>

int Random::_seed = 0;

rand_t Random::between(rand_t min, rand_t max, dist_t type) {
  return min + (max - min) * value(type);
}

rand_t Random::ranged(rand_t min, rand_t max, dist_t type) {
  return min + max * value(type);
}

rand_t Random::value(dist_t type) {
  if(_seed == 0) {
    initialize();
  }

  switch(type){
    case RANDOM_DEFAULT:
    default:
      return valDefault();
  }
}

void Random::initialize() {
  _seed = time(NULL);
  srand(_seed);
}

rand_t Random::valDefault() {
  return (rand_t)rand()/(rand_t)RAND_MAX;
}
