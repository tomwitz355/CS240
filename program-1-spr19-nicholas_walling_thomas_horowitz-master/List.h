#ifndef HEADERVAR_LIST
#define HEADERVAR_LIST
#include "Planet.h"

class Node{
	public:
		Planet * planet;
		Node * next;
		Node();
		~Node();
};

class List{
	public:
		Node * head;
		Node * tail;
		int list_size;
		List();
		~List();
		void insert(int index, Planet * p);
		Planet * read(int index);
		bool remove(int index);
		unsigned size(){return (unsigned)this->list_size;}
		void decrementSize(){this->list_size--;}
		void incrementSize(){this->list_size++;}
};

#endif
