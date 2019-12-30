#include "Scanner.h"


Scanner::Scanner(std::vector<Planet> planets){
  Heap<Planet> temp(planets);
  this->planets = temp;
}

std::vector<Planet> Scanner::scan(unsigned int num_planets){
  if(num_planets > this->planets.size()){
    num_planets = this->planets.size();
  }
  std::vector<Planet> temp;
  for(int i = 0; i < num_planets; i++){
	
    int seed = rand() % 2;
    int change;
    if(seed == 0){
      change = -1;
    }
    if(seed == 1){
      change = 1;
    }
	Planet p = this->planets.getPriority();
    if(p.getProbability() != 100 && p.getProbability() != 0){
      p.refine(change);
    }
    	temp.push_back(p);
  }
  return temp;
}

void Scanner::addPlanet(Planet p){
  this->planets.addElement(p);
}
