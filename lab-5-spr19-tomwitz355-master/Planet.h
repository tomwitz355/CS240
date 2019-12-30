#ifndef PLANET_H
#define PLANET_H

#include <cstdlib>
#include <iostream>
#include <vector>

class Planet{
private:
	unsigned long id;
	unsigned int distance;
	char type;

public:
	Planet();
	unsigned long getID(){return this->id;}
	unsigned int getDistance(){return this->distance;}
	char getType(){return this->type;}
};

#endif
