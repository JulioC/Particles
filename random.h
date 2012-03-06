#ifndef RANDOM_H
#define RANDOM_H

typedef float rand_t;

class Random {
public:
  enum dist_t {
    RANDOM_DEFAULT,
  };

  static rand_t between(rand_t min, rand_t max, dist_t type = RANDOM_DEFAULT);
  static rand_t ranged(rand_t min, rand_t range, dist_t type = RANDOM_DEFAULT);
  static rand_t value(rand_t multiplier = 1, dist_t type = RANDOM_DEFAULT);

protected:
  static int _seed;

  static void initialize();

  static rand_t valDefault();

private:
  Random();
  Random(const Random &);
};

#endif // RANDOM_H
