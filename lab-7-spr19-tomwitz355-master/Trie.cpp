#include "Trie.h"


Trie::Trie(){
	this->root = new Node();
	this->num_leaves = 0;
	this->num_nodes = 0;
}

Trie::~Trie(){
	deleteHelper(this->root);
}

void Trie::deleteHelper(Node * node){
	for(auto i : node->children){
		deleteHelper(i.second);
	}
	delete node;
}

bool Trie::add(std::pair<std::string, double> key){
	Node *temp = this->root;
	bool newNode = false;
	this->num_nodes++;

	for(int i = 0; i < key.first.size(); i++){
		if(temp->children.count(key.first[i]) == 0){
			Node *next = new Node();
			next->character = key.first[i];
			temp->children[key.first[i]] = next;
			temp = next;
			newNode = true;
			this->num_nodes++;
		}
		else{
			temp = temp->children[key.first[i]];
		}
	}
	if(!newNode){
		return false;
	}
	temp->probability = key.second;
	this->num_leaves++;
	return true;
}

void Trie::printTrie(){
	printTrieHelper(this->root);
	std::cout << "Trie complete" << std::endl;
}

void Trie::printTrieHelper(Node *node){
		std::cout << "Parent: (key) " << node->character << " : "<< "(value) "<< node->probability<< std::endl;
		for(auto i : node->children){
			std::cout << "----> Child: (key) " << i.first << " : "<< "(value) "<< i.second->probability << std::endl;
		}
		std::cout << "\n" << std::endl;
		for(auto i : node->children){
			printTrieHelper(i.second);
		}
}

double Trie::search(std::string key){
	Node *temp = this->root;
	for(int i = 0; i < key.size(); i++){
		if(temp->children.count(key[i]) == 0){
			return -1;
		}
		else{
			temp = temp->children[key[i]];
		}
	}
	return temp->probability;
}
