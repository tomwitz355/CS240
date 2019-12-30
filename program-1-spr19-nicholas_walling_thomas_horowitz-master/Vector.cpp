#include "Vector.h"

//constructor sets up an array called vector
Vector::Vector(){
	this->vector = NULL;
	this->planets= 0;
	this->vector_size = 0;
}

/** for loops through vector to delete all the elements then deletes
the vector itself
*/
Vector::~Vector(){
	for(int i = 0; i < size(); i++){
		delete vector[i];
	}
	delete[] vector;
}

void Vector::insert(int index, Planet *p){
	if(index > this->size()){
		Planet **temp = new Planet*[index+1];
		for(int i = 0; i < index+1; i++){
			temp[i] = NULL;
		}
		for(int i = 0; i < this->size(); i++){
			temp[i] = this->vector[i];
		}
		temp[index] = p;
		delete[] this->vector;
		this->vector = temp;
		this->planets++;
		this->vector_size = index+1;
	}
	else{
		Planet **temp = new Planet*[this->size()+1];
		for(int i = 0; i < size(); i++){
			if(i != index){
				temp[i] = this->vector[i];
			}
		}
		temp[index] = p;
		delete[] this->vector;
		this->vector = temp;
		this->vector_size++;
		this->planets++;
	}
}

Planet* Vector::read(int index){
	if(this->vector_size < index || index < 0){
		return NULL;
	}
	return this->vector[index];
}

bool Vector::remove(int index){
	if(0 > index || index >= this->vector_size){
		return false;
	}
	else{
		Planet ** temp = new Planet*[this->vector_size-1];
		for(int i = 0; i < this->size()-1; i++){
			temp[i] = NULL;
		}
		if(this->vector[index] != NULL){
			delete this->vector[index];
		}
		for(int i = 0; i < this->vector_size-1; i++){
			if(i < index){
				temp[i] = this->vector[i];
			}
			else{
				temp[i] = this->vector[i+1];
			}
		}
		
		delete[] this->vector;
		this->vector = temp;
		this->planets--;
		this->vector_size--;
		return true;
	}
}

unsigned int Vector::size(){
	return this->vector_size;
}
