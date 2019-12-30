#include "Planet.h"
#include <cstdlib>
#include <iostream>
//PLANET METHOD IMPLEMENTATION

Planet::Planet(int dist){	
	this->distance = dist;
    	this->pos = rand() % 360;
	char list[] = "hrg";
	this->type = list[rand() % 3];
}

//move planet +1 unit around the star (between 0-359)
int Planet::orbit(){
	if(this->pos < 359){
		this->pos++;
	}
	else{
		this->pos = 0;
	}
	return this->pos;
}
