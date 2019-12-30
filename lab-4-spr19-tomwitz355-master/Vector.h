#ifndef HEADER_H
#define HEADER_H

#include <cstdlib>
#include <iostream>

template <class T>
class Vector{
private:
	int vector_size;
public:
	T *vector;
	Vector(int);
	Vector(const Vector<T> & v);
	~Vector();
	T& operator [](std::size_t index);
	int size();
	void clear();
};

template <class T>
Vector<T>::Vector(int size){
	this->vector_size = size;
	this->vector = new T[size];
}

template <class T>
Vector<T>::Vector(const Vector<T> & v){
	int new_size = v.vector_size;
	this->vector = new T[new_size];
	this->vector_size = new_size;
	for(int i = 0; i < this->vector_size; i++){
		this->vector[i] = v.vector[i];
	}
}

	template <class T>
	Vector<T>::~Vector(){
		delete []this->vector;
	}

template <class T>
T& Vector<T>::operator [](std::size_t index){
		return this->vector[index];
}

template <class T>
int Vector<T>::size(){
	return this->vector_size;
}

template <class T>
void Vector<T>::clear(){
	for(int i = 0; i < this->vector_size; i++){
		this->vector[i] = NULL;
	}
	delete[] this->vector;
	this->vector = new T[0];
	this->vector_size = 0;
}
//
// template <class T>
// void Vector::insert(int index, T object){
// 	if(index > this->size()){
// 		Planet **temp = new Planet*[index+1];
// 		for(int i = 0; i < index+1; i++){
// 			temp[i] = NULL;
// 		}
// 		for(int i = 0; i < this->size(); i++){
// 			temp[i] = this->vector[i];
// 		}
// 		temp[index] = p;
// 		delete[] this->vector;
// 		this->vector = temp;
// 		this->planets++;
// 		this->vector_size = index+1;
// 	}
// 	else{
// 		Planet **temp = new Planet*[this->size()+1];
// 		for(int i = 0; i < size(); i++){
// 			if(i != index){
// 				temp[i] = this->vector[i];
// 			}
// 		}
// 		temp[index] = p;
// 		delete[] this->vector;
// 		this->vector = temp;
// 		this->vector_size++;
// 		this->planets++;
// 	}
// }
//
// template <class T>
//  Vector::read(int index){
// 	if(this->vector_size < index || index < 0){
// 		return NULL;
// 	}
// 	return this->vector[index];
// }
//
// template <class T>
// bool Vector::remove(int index){
// 	if(0 > index || index >= this->vector_size){
// 		return false;
// 	}
// 	else{
// 		Planet ** temp = new Planet*[this->vector_size-1];
// 		for(int i = 0; i < this->size()-1; i++){
// 			temp[i] = NULL;
// 		}
// 		if(this->vector[index] != NULL){
// 			delete this->vector[index];
// 		}
// 		for(int i = 0; i < this->vector_size-1; i++){
// 			if(i < index){
// 				temp[i] = this->vector[i];
// 			}
// 			else{
// 				temp[i] = this->vector[i+1];
// 			}
// 		}
//
// 		delete[] this->vector;
// 		this->vector = temp;
// 		this->planets--;
// 		this->vector_size--;
// 		return true;
// 	}
// }

#endif
