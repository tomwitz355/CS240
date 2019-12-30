#ifndef PLANET_H
#define PLANET_H

#include <cstdlib>
#include <string>
#include <iostream>

class Planet{
private:
  std::string id;
  double probability;

public:
  Planet(std::string, double);
  std::string getName();
  double getProbability();
  double refine(double);
  bool operator >(const Planet& other);
  bool operator <(const Planet& other);
  bool operator >=(const Planet& other);
  bool operator <=(const Planet& other);
  bool operator ==(const Planet& other);
  bool operator !=(const Planet& other);
};

#endif
