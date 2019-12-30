#ifndef PROBE_H
#define PROBE_H

#include <cstdlib>
#include <iostream>
#include <queue>
#include "Planet.h"
#include "Star.h"
#include <algorithm>
#include <random>

class Probe{
private:
  std::queue<Planet> planets;

public:
  Probe();
  std::vector<Planet> getHabitable(Star s);
  void addToQueue(Planet p);
  Planet getNext();
  std::queue<Planet>& getQueue(){return this->planets;}
  void shuffle();

};



#endif
