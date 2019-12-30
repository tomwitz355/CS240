#include "Star.h"

Planet::Planet(int distance, int id){
	this->id = id;
	this->distance = distance;
	this->pos = 0;
}

int Planet::getID(){
	return this->id;
}

int Planet::orbit(){
	if(this->pos != 359){
		return this->pos += 1;
	}
	this->pos = 0;
	return this->pos;

}

int Planet::getDistance(){
	return this->distance;
}

int Planet::getPos(){
	return this->pos;
}

Star::Star(int max_planets){
	this->max_planets = max_planets;
	this->current_planets = 0;
}

bool Star::addPlanet(){
	if(this->current_planets >= this->max_planets){
		return false;
	}

	int next_id = this->current_planets;
	int distance = rand() % 3000;
	Planet *planet = new Planet(distance, next_id);
	this->planets[next_id] = *planet;
	std::cout <<
	current_planets++;
	return true;
}

Planet Star::getFurthest(){
	Planet *furthest = &this->planets[0];
	for(int i = 0; i < this->current_planets; i++){
		if(furthest->getDistance() < this->planets[i].getDistance()){
			furthest = &this->planets[i];
		}
	}
	return *furthest;
}

void Star::orbit(){
	for(int i = 0; i < this->current_planets; i++){
		this->planets[i].orbit();
	}
}

void Star::printStarInfo(){
	std::cout << "The star currently has " << this->current_planets << " planets." << std::endl;
	std::cout << "The star can support up to " << this->max_planets << " planets." << std::endl;
	for(int i = 0; i < this->current_planets; i++){
		std::cout << "\tPlanet " << i << " is " << this->planets[i].getDistance() << " million miles away at position "<< this->planets[i].getPos() << " around the star."<< std::endl;
	}
}

int Star::getCurrentNumPlanets(){
	return this->current_planets;
}

int Star::getMaxPlanets(){
	return this->max_planets;
}
