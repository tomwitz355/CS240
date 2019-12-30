#include "Star.h"
#include "Planet.h"
#include <cstdlib>
#include <iostream>

//############################################
//Starlist Class Methods Implementation

//Constructor for Starlist
Starlist::Starlist(){
	this->list = new List();
	this->current_num_planets = 0;
}

Starlist::~Starlist(){
	delete list;
}

//Adds planet to Star, returns true on success
long Starlist::addPlanet(){
	//create Planet
	int dist = rand() % 3000;
	Planet * newP = new Planet(dist);

	//Insert into List
	this->list->insert(getCurrentNumPlanets(), newP);
	this->current_num_planets++;


	return (long) newP;

}

bool Starlist::removePlanet(long id_NUM){
	Node * temp = this->list->head;
	int i;
	bool isDeleted = false;

	//find id to be deleted
	for(i = 0; i < getCurrentNumPlanets(); i++){
		if(temp->planet->getID() == id_NUM){
			temp = NULL;
			this->list->remove(i);
			isDeleted = true;
			break;
		}
		temp = temp->next;
	}
	if(isDeleted){ this->current_num_planets--;return true;}
	return false;
}

Planet * Starlist::getPlanet(long num_ID){
	int i;
	Node * temp = this->list->head;
	for(i = 0; i < this->current_num_planets;i++){
		if(temp->planet->getID() == num_ID){ return temp->planet;}
		temp = temp->next;
	}
	return NULL;
}

//call orbit on all planets
void Starlist::orbit(){
	int i;
	Node * temp = this->list->head;
	for(i = 0; i < this->getCurrentNumPlanets(); i++){
		temp->planet->orbit();
		temp = temp->next;
	}
}

//prints star info
void Starlist::printStarInfo(){
	Node * temp = this->list->head;
	printf("The star has %d planets.\n", this->getCurrentNumPlanets());
	int i;
	std::cout << "Planets:" << std::endl;
	for(i = 0; i< this->getCurrentNumPlanets();i++){
		printf("Planet %d is %d million miles away at position %d around the star.\n", temp->planet->getID(), temp->planet->getDistance(), temp->planet->getPos());
		temp = temp->next;
	}
}



Starvector::Starvector(){
	this->vector = new Vector();
}

Starvector::~Starvector(){

	delete this->vector;

}

long Starvector::addPlanet(){
	Planet *p = new Planet(rand() % 3000);
	this->vector->insert(this->vector->size(), p);
	return p->getID();
}

bool Starvector::removePlanet(long id_NUM){
	for(int i = 0; i < this->vector->size(); i++){
		if(this->vector->read(i)->getID() == id_NUM){
			this->vector->remove(i);
			return true;
		}
	}
	return false;
}

Planet *Starvector::getPlanet(long id_NUM){
	for(int i = 0; i < this->vector->size(); i++){
		if(this->vector->read(i)->getID() == id_NUM){
			return this->vector->read(i);
		}
	}
	return NULL;
}

//call orbit on all planets
void Starvector::orbit(){
	int i;
	for(i = 0; i<this->vector->planets; i++){
		this->vector->read(i)->orbit();
	}
}

//prints star info
void Starvector::printStarInfo(){
	printf("The star has %d planets.\n", this->vector->planets);
	int i;
	std::cout << "Planets:" << std::endl;
	for(i = 0; i< this->vector->planets;i++){
		printf("Planet %d is %d million miles away at position %d around the star.\n", this->vector->read(i)->getID(), this->vector->read(i)->getDistance(), this->vector->read(i)->getPos());
	}
}

unsigned int Starvector::getCurrentNumPlanets(){
	return this->vector->planets;
}
