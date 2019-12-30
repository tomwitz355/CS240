#include "Planet.h"

Planet::Planet(){
	this->id = (unsigned long)this;
	this->distance = rand() %3001;
  	int habit = rand() % 3;
  	switch(habit){
    		case 0: this->type = 'h';
    		case 1: this->type = 'r';
    		case 2: this->type = 'g';
  	}
}
