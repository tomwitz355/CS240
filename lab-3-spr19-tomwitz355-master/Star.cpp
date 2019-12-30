#include "Star.h"

Star::Star(){
	this->planets = NULL;
	this->current_planets = 0;
}

Star::~Star(){
	for(int i = 0; i < this->current_planets; i++){
		delete planets[i];
	}
	delete[] planets;
}

int Star::addPlanet(){

	int next_id = this->current_planets;
	int distance = rand() % 3000;
	Planet *planet = new Planet(distance, next_id);

	Planet **temp = new Planet*[1+this->current_planets];
	for(int i = 0; i < this->current_planets; i++){
		temp[i] = this->planets[i];
	}
	temp[next_id] = planet;
	delete[] this->planets;
	this->planets = temp;
	this->current_planets++;
	return planet->getID();
}

bool Star::removePlanet(int id){
	bool remove = false;
	for(int i = 0; i < this->current_planets; i++){
		if(this->planets[i]->getID() == id){
			remove = true;
		}
	}
	if(remove){
		int index = 0;
		Planet **temp = new Planet*[this->current_planets-1];
		for(int i = 0; i < this->current_planets; i++){
			if(this->planets[i]->getID() != id){
				temp[index] = this->planets[i];
				index++;
			}
			if(this->planets[i]->getID() == id){
				delete this->planets[i];
			}
		}
		this->current_planets--;
		delete[] this->planets;
		this->planets = temp;
		return remove;
	}
	return remove;
}

Planet * Star::getPlanet(int id){
	for(int i = 0; i < this->current_planets; i++){
		if(this->planets[i]->getID() == id){
			return this->planets[i];
		}
	}
	return NULL;
}

Planet Star::getFurthest(){
	Planet *furthest = this->planets[0];
	for(int i = 0; i < this->current_planets; i++){
		if(furthest->getDistance() < this->planets[i]->getDistance()){
			furthest = this->planets[i];
		}
	}
	return *furthest;
}

void Star::orbit(){
	for(int i = 0; i < this->current_planets; i++){
		this->planets[i]->orbit();
	}
}

void Star::printStarInfo(){
	std::cout << "The star currently has " << this->current_planets << " planets." << std::endl;
	std::cout << "Planets:" << std::endl;
	for(int i = 0; i < this->current_planets; i++){
		std::cout << "\tPlanet " << this->planets[i]->getType() << this->planets[i]->getID() << " is " << this->planets[i]->getDistance() << " million miles away at position "<< this->planets[i]->getPos() << " around the star."<< std::endl;
	}
}

int Star::getCurrentNumPlanets(){ return this->current_planets;}
