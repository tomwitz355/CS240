#include "Hash.h"

Node::Node(){
	this->key = "";
	this->value = -1;
}

Hash::Hash(unsigned int size){
	this->hash = new Node[size];
	this->max_size = size;
}

Hash::~Hash(){
	delete[] this->hash;
}

unsigned int Hash::hasher(std::string key){
	int val = 0;
	for(int i = 0; i < key.size(); i++){
		val += key[i];
	}
	return val % this->max_size;
}

bool Hash::insert(std::string key, double value){
	bool isFull = true;
	for(int i = 0; i < this->max_size; i++){
		if(this->hash[i].value == -1){
			isFull = false;
		}
	}
	if(isFull){
		return false;
	}

	Node temp = Node();
	temp.key = key;
	temp.value = value;
	unsigned int index = hasher(key);
	while(this->hash[index].value != -1){
		if(index == this->max_size -1 ){
			index = 0;
		}
		else{
			index++;
		}
	}
	this->hash[index] = temp;
	return true;
}

bool Hash::empty(){
	bool isEmpty = true;
	for(int i = 0; i < this->max_size; i++){
		if(this->hash[i].value != -1){
			isEmpty = false;
		}
	}
	return isEmpty;
}

bool Hash::remove(std::string key){
	int index = hasher(key);
	if(this->hash[index].key == key){
		this->hash[index].value = -1;
		this->hash[index].key = "";
		return true;
	}
	int temp = 0;
	if(index == this->max_size -1){
		temp = 0;
	}
	if(index != this->max_size -1){
		temp = index + 1;
	}
	while(temp != index){
		if(this->hash[temp].key == key){
			this->hash[temp].value = -1;
			this->hash[temp].key = "";
			return true;
		}
		if(temp != this->max_size -1){
			temp++;
		}
		else{
			temp = 0;
		}
	}
	return false;
}

double Hash::find(std::string key){
	int index = hasher(key);
	if(this->hash[index].key == key){
		return this->hash[index].value;
	}
	int temp = 0;
	if(index == this->max_size -1){
		temp = 0;
	}
	if(index != this->max_size -1){
		temp = index + 1;
	}
	while(temp != index){
		if(this->hash[temp].key == key){
			return this->hash[temp].value;
		}
		if(temp != this->max_size -1){
			temp++;
		}
		else{
			temp = 0;
		}
	}
	return -1;
}
