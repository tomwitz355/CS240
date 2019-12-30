#ifndef PARSER_H
#define PARSER_H

#include "Planet.h"
#include <cstdlib>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <memory>

class Parser{
    private:
        std::vector <Planet> vect;
    public:
        Parser(std::string filename);
        std::vector<Planet> getPlanets(){
            return this->vect;
        }
};

#endif