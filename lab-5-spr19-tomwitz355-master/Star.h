#ifndef STAR_H
#define STAR_H

#include <cstdlib>
#include <iostream>
#include <vector>
#include "Planet.h"

class Star{
private:
	std::vector<Planet> planets;

public:
	Star();
	unsigned long addPlanet();
	bool removePlanet(unsigned long);
	Planet *getPlanet(unsigned long);
	std::vector<Planet>& getPlanets(){return this->planets;}
};

#endif
