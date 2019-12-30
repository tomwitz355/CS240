#include <cstdlib>
#include <iostream>
#include "Planet.h"
#include "Star.h"

#ifndef VECTOR_H
#define VECTOR_H

class Vector{
	public:
		Planet **vector;
		unsigned int vector_size;
		unsigned int planets;
		Vector();
		~Vector();
		void insert(int, Planet*);
		Planet* read(int);
		bool remove(int);
		unsigned int size();
};

#endif
