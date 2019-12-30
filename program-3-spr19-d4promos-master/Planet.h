#ifndef PLANET_H
#define PLANET_H

#include <cstdlib>
#include <string>
#include <iostream>
#include <list>
#include <vector>
#include <cmath>
#include <algorithm>
#include <float.h>

class Planet{
private:
	std::string planetName;
	long xCoor;
	long yCoor;
	long zCoor;
	std::list<Planet*>adjacent;


public:
	bool visited = false;
	Planet * optimalPrev = nullptr;
	double totalDistance = LDBL_MAX;
	Planet(std::string, long, long, long);
	std::string getName(){return this->planetName;}
	long getXCoor(){return this->xCoor;}
	long getYCoor(){return this->yCoor;}
	long getZCoor(){return this->zCoor;}
	void update(std::vector<Planet*>);
	std::list<Planet*> getAdjacent(){return this->adjacent;}
	double distanceBetween(Planet *);

};


#endif
