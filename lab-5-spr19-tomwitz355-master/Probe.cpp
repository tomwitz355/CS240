#include "Probe.h"

Probe::Probe(){
  std::queue<Planet> temp;
  this->planets = temp;
}

std::vector<Planet> Probe::getHabitable(Star s){
  std::vector<Planet> habitable;
  for(int i = 0; i < s.getPlanets().size(); i++){
    if(s.getPlanets()[i].getType() == 'h'){
      if(s.getPlanets()[i].getDistance() >= 60 && s.getPlanets()[i].getDistance() <= 140){
        habitable.push_back(s.getPlanets()[i]);
      }
    }
  }
  return habitable;
}

void Probe::addToQueue(Planet p){
  this->planets.push(p);
}

Planet Probe::getNext(){
  Planet temp = this->planets.front();
  this->planets.pop();
  return temp;
}

void Probe::shuffle(){
  std::vector<Planet> temp;
  for(int i = 0; i < this->planets.size(); i++){
    Planet p = this->planets.front();
    this->planets.pop();
    temp.push_back(p);
  }

  std::random_shuffle(temp.begin(), temp.end());
  for(auto p = temp.begin(); p != temp.end(); p++){
    this->planets.push(*p);
  }
}
