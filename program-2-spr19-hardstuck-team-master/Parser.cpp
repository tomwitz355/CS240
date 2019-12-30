#include "Parser.h"
using namespace std;

Parser::Parser(string filename){
    ifstream file(filename); 
    if(file.is_open()){
        string id;
        double probability;

        while(file >> id >> probability){
            unique_ptr<Planet> newP (new Planet(id, probability)); //lazy so no memory management
            vect.push_back(*(newP.get()));
        }
    }
    
}