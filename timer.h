#ifndef TIMER_H
#define TIMER_H

#include <QTime>

class Timer {
public:
  Timer(long int updateInterval = 1000);

  void start();
  void stop();

  void update();

  inline float fps() const { return _fps; }
  float elapsed() const { return _stopped ? .0f : (float)_elapsed / 1000.0; }

private:
  QTime _time;

  long int _lastTime;
  long int _elapsed;

  bool _stopped;

  long int _updateInterval;
  long int _lastUpdate;
  long int _frames;
  float _fps;
};
#endif