#include "Planet.h"

bool compare(std::pair<Planet*, double> p1, std::pair<Planet*, double> p2){
	return (p1.second < p2.second);
}

Planet::Planet(std::string planetName, long xCoor, long yCoor, long zCoor){
	this->planetName = planetName;
	this->xCoor = xCoor;
	this->yCoor = yCoor;
	this->zCoor = zCoor;
}

void Planet::update(std::vector<Planet*> planets){
	std::vector<std::pair<Planet*, double>>temp;
	for(int i = 0; i < planets.size(); i++){
		double dis = sqrt(pow((planets[i]->getXCoor() - this->getXCoor()), 2) + pow((planets[i]->getYCoor() - this->getYCoor()), 2) + pow((planets[i]->getZCoor() - this->getZCoor()), 2));
		if(dis != 0){
			std::pair<Planet*, double>p;
			p.first = planets[i];
			p.second = dis;
			temp.push_back(p);
		}
	}
	std::sort(temp.begin(), temp.end(), compare);

	this->adjacent.push_back(temp[0].first);
	this->adjacent.push_back(temp[1].first);
	this->adjacent.push_back(temp[2].first);
	this->adjacent.push_back(temp[3].first);
}

double Planet::distanceBetween(Planet *p){
	double dis = sqrt(pow((p->getXCoor() - this->getXCoor()), 2) + pow((p->getYCoor() - this->getYCoor()), 2) + pow((p->getZCoor() - this->getZCoor()), 2));
	return dis;
}
