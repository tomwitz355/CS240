#ifndef RANDOMVAR
#define RANDOMVAR
#include "Planet.h"
#include "List.h"
#include "Vector.h"

class Starlist{
	private:
		List * list;
		int current_num_planets;
	public:
		Starlist();
		~Starlist();
		long addPlanet();
		bool removePlanet(long);
		Planet * getPlanet(long);
		void orbit();
		void printStarInfo();
		unsigned int getCurrentNumPlanets(){ return this->current_num_planets;}
};

class Starvector{

	public:
		Vector * vector;
		Starvector();
		~Starvector();
		long addPlanet();
		bool removePlanet(long);
		Planet * getPlanet(long);
		void orbit();
		void printStarInfo();
		unsigned int getCurrentNumPlanets();
};

#endif
