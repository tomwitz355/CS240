#include "Planet.h"

Planet::Planet(std::string id, double probability){
  this->id = id;
  this->probability = probability;
}

std::string Planet::getName(){
  return this->id;
}

double Planet::getProbability(){
  return this->probability;
}

double Planet::refine(double r){
  if((r + this->probability) >= 100.0){
    this->probability = 100;
  }
  else if((r + this->probability) <= 0.0){
    this->probability = 0;
  }
  else{
    this->probability += r;
  }
  return this->probability;
}

bool Planet::operator>(const Planet& other){
  return this->probability > other.probability;
}

bool Planet::operator<(const Planet& other){
  return this->probability < other.probability;
}

bool Planet::operator>=(const Planet& other){
  return this->probability >= other.probability;
}

bool Planet::operator<=(const Planet& other){
  return this->probability <= other.probability;
}

bool Planet::operator!=(const Planet& other){
  return this->probability != other.probability;
}

bool Planet::operator==(const Planet& other){
  return this->probability == other.probability;
}
