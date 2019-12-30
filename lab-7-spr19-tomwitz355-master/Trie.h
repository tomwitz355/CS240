#ifndef TRIE_H
#define TRIE_H

#include <cstdlib>
#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include <memory>

class Trie{
private:
	class Node{
	public:
		double probability;
		char character;
		std::map<char, Node*> children;
		Node(){
			this->probability = -1;
			this->character = '?';
		}
	};
	Node *root;
	int num_leaves;
	int num_nodes;

public:
	Trie();
	~Trie();
	bool add(std::pair<std::string, double>);
	unsigned int numLeaves(){return this->num_leaves;}
	unsigned int numNodes(){return this->num_nodes;}
	void printTrie();
	void printTrieHelper(Node *);
	double search(std::string);
	void deleteHelper(Node *);
};

#endif
