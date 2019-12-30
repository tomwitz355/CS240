#ifndef STAR_H
#define STAR_H

#include <cstdlib>
#include <iostream>
#include "Planet.h"

class Star{
	private:
        	int current_planets;
        	int next_id;
	public:
        	Planet **planets;
        	Star();
					~Star();
					int addPlanet();
					bool removePlanet(int);
        	Planet getFurthest();
        	void orbit();
        	void printStarInfo();
        	int getCurrentNumPlanets();
					Planet * getPlanet(int);
        //you may add any additional methodas you may need.
};

#endif
