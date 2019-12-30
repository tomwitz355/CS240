#ifndef SCANNER_H
#define SCANNER_H

#include <cstdlib>
#include <iostream>
#include <vector>
#include "Planet.h"
#include "Heap.h"

class Scanner{
private:
  Heap<Planet> planets;
public:
  Scanner(std::vector<Planet>);
  std::vector<Planet> scan(unsigned int num_planets);
  void addPlanet(Planet P);
  Heap<Planet> getHeap(){return this->planets;}
};


#endif
