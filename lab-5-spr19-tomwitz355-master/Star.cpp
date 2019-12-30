#include "Star.h"

Star::Star(){
	std::vector<Planet> temp;
	this->planets = temp;
}


unsigned long Star::addPlanet(){
	Planet temp = Planet();
	this->planets.push_back(temp);
	return temp.getID();
}

bool Star::removePlanet(unsigned long id){
	for(int i = 0; i < this->planets.size(); i++){
		if(this->planets[i].getID() == id){
			this->planets.erase(this->planets.begin()+i);
			return true;
		}
	}
	return false;
}

Planet * Star::getPlanet(unsigned long id){
	for(int i = 0; i < this->planets.size(); i++){
		if(this->planets[i].getID() == id){
			return &this->planets[i];
		}
	}
	return nullptr;
}
