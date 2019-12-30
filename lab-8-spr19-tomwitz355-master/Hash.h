#ifndef TRIE_H
#define TRIE_H

#include <cstdlib>
#include <string>
#include <iostream>
#include <cmath>

class Node{
public:
	std::string key;
	double value;
	Node();
};


class Hash{
private:
	Node *hash;
	int max_size;
public:
	Hash(unsigned int);
	~Hash();
	unsigned int hasher(std::string);
	bool insert(std::string, double value);
	bool empty();
	int size(){return this->max_size;}
	Node *getTable(){return this->hash;}
	bool remove(std::string);
	double find(std::string);
};


#endif
