#include "random.h"

#include <stdlib.h>
#include <time.h>

int Random::_seed = 0;

rand_t Random::between(rand_t min, rand_t max, dist_t type) {
  return min + value((max - min), type);
}

rand_t Random::ranged(rand_t min, rand_t range, dist_t type) {
  return min + value(range, type);
}

rand_t Random::value(rand_t multiplier, dist_t type) {
  if(_seed == 0) {
    initialize();
  }

  rand_t rand;

  switch(type){
    case RANDOM_DEFAULT:
    default:
      rand = valDefault();
  }

  return multiplier * rand;
}

void Random::initialize() {
  _seed = time(NULL);
  srand(_seed);
}

rand_t Random::valDefault() {
  return (rand_t)rand()/(rand_t)RAND_MAX;
}
