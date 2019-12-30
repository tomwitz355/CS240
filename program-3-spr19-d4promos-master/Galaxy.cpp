#include "Galaxy.h"
#include <float.h>
using namespace std;

Galaxy::Galaxy(string filename){
	ifstream file(filename);
	if(file.is_open()){
		string name;
		long x = 0,y=0,z=0;
		while(file >> name >> x >> y>> z){
		    Planet*newP = new Planet(name, x, y, z); 
		    galaxy.push_back(newP);
		}
		for(Planet* p : galaxy){
			p->update(galaxy); //sets adjacencies	
		}
	}
}
Galaxy::~Galaxy(){
	for(Planet * p : galaxy) delete p;
}
unsigned int Galaxy::size(){
	return (unsigned int)galaxy.size();
}
Planet* Galaxy::findByName(std::string planetName){
	for(Planet* p : galaxy){
		if(p->getName() == planetName) return p;
	}
	return nullptr;
}



Planet* Galaxy::minDistance(Planet* current){
	/*************
	Finds next planet for Dijkstra's algorithm


	*************/
	Planet* shortest = current;

	//Check for adjacents first -> are there unexplored connections?
	for(Planet* p: current->getAdjacent()){
		if(!p->visited && p->totalDistance < shortest->totalDistance){
			shortest = p;
		}
	}
	if(shortest != current) return shortest;
	//there is a non-adjacent node that hasn't been visited, look there
	for(Planet* p : galaxy){
		if(shortest == current && p!= current && !(p->visited)) shortest = p;
		else{
			if(!(p->visited) && p->totalDistance < shortest->totalDistance){
				shortest = p;
			}
		}
	}
	if(shortest == current) return nullptr;
	return shortest;
}
void Galaxy::aux(){
	for(Planet* p : galaxy){
		if(p->optimalPrev == nullptr){ 

			continue;
		}
	}
}
vector<Planet*> Galaxy::shortestPath(Planet* start, Planet* dest){
	vector<Planet*> path;
	//zero everything out
	for(Planet* p : galaxy){
		p->totalDistance = LDBL_MAX;
		p->optimalPrev = nullptr;
		p->visited = false;
	}
	start->totalDistance = 0;
	Planet* current = start;
	//check for all adjacents

	for(int i = 0; i < galaxy.size(); i++){
		if(current->visited) break;
		if(current == dest){
			break;
		}
		for(Planet* p : current->getAdjacent()){
			/*start's total distance begins at 0
			  when moving to a new node, it's distance will be changed first, so INF is never encoutnered


			*/
			double dist = current->totalDistance + p->distanceBetween(current); // (weight to current) + (distance from current to p) = p's weight
			//is this path shorter? if so, update values
			if(dist <= p->totalDistance){
				p->totalDistance = dist;
				p->optimalPrev = current;
			}
		}
		current->visited = true;
		current = minDistance(current);
		if(current == nullptr){ 
			break;
		}	
		
			
	}
	aux();
	current = dest;
	while(current != start){
		if(current->optimalPrev == nullptr) {
			vector<Planet*> noPath;
			return noPath;
		}

		path.push_back(current);
		current = current->optimalPrev;

	}
	path.push_back(start);
	reverse(path.begin(), path.end());

	cout<<endl;
	return path;	
}
double Galaxy::pathDistance(Planet* start, Planet* dest){
	if(start == dest) return 0;
	vector<Planet*> path = shortestPath(start, dest);
	if(path.size() == 0) return LDBL_MAX;
	return path[path.size()-1]->totalDistance;

}



