#include "Planet.h"


Planet::Planet(int distance, int id){
	this->id = id;
	this->distance = distance;
	this->pos = rand() % 360;
  int habit = rand() % 3;
  switch(habit){
    case 0: this->type = 'h';
    case 1: this->type = 'r';
    case 2: this->type = 'g';
  }
}

int Planet::getID(){ return this->id;}

int Planet::getDistance(){return this->distance;}

int Planet::getPos(){	return this->pos;}

char Planet::getType(){return this->type;}

int Planet::orbit(){
	if(this->pos != 359){
    this->pos += 1;
		return this->pos;
	}
	this->pos = 0;
	return this->pos;

}
