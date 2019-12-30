#ifndef GALAXY_HEADER
#define GALAXY_HEADER 

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include "Planet.h"
#include <fstream>
#include <memory>
#include <algorithm>

class Galaxy{
	private:
		Planet * minDistance(Planet * current);
	public:
		std::vector<Planet* > galaxy;
		Galaxy(std::string filename);
		~Galaxy();
		unsigned int size();
		Planet* findByName(std::string planetName);
		std::vector<Planet *> shortestPath(Planet * start, Planet * dest);
		double pathDistance(Planet * start, Planet * dest);
		void aux();

};

#endif
