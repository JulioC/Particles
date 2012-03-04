#include "timer.h"

Timer::Timer(long int updateInterval) :
  _time(),
  _lastTime(0),
  _elapsed(0),
  _stopped(true),
  _updateInterval(updateInterval),
  _lastUpdate(0),
  _frames(0),
  _fps(0)
   {
  _time.start();
}

void Timer::start() {
  if(!_stopped) {
    return;
  }

  _time.restart();
  _lastTime = 0;
  _elapsed = 0;
  _lastUpdate = 0;

  _stopped = false;
}

void Timer::stop() {
  if(_stopped) {
    return;
  }

  _time.restart();

  _stopped = true;
}


void Timer::update() {
  if(_stopped) {
    return;
  }

  long int current = _time.elapsed();

  _frames += 1;
  if(current - _lastUpdate >= _updateInterval) {
    //@TODO: find out a better way to calculate frame rate
    _fps = _frames / ((float)(current - _lastUpdate) / 1000.0);
    _lastUpdate = current;
    _frames = 0;
  }

  _elapsed = current - _lastTime;
  _lastTime = current;
}