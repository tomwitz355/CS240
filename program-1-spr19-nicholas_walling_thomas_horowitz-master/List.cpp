#include "List.h"
#include <iostream>
#include <cstdlib>

//Implementation of List Class Methods

List::List(){
	this->head = NULL;
	this->tail = NULL;
	this->list_size = 0;
}

List::~List(){
	Node * temp = this->head;
	Node * toDel = NULL;
	int i;
	for(i = 0; i < this->size(); i++){
		toDel = temp;
		temp = temp->next;
		delete toDel;
		toDel = NULL;
	}
}

//Params: Planet * p is the planet being inserted into the list
//int index is the index to insert at the list
//Inserts an element at index. If index is out of bounds, appends to the list
void List::insert(int index, Planet * p){
	Node * nnode = new Node();
	Node * temp = NULL;	

	nnode->planet = p;
	//if List is empty
	if(this->size() == 0){
		nnode->next = NULL;
		this->head = nnode;
		this->tail = nnode;
	}

	//check if index is out of bounds, append to list
	else if(index > this->size() - 1){
		temp = this->head;
		this->tail->next = nnode;
		this->tail = nnode;
	}
	else{
		int i;
		temp = this->head;
		for(i = 0; i < index - 1; i++){
			temp = temp->next;
		}
		nnode->next = temp->next;
		temp->next = nnode;
	}
	
	//increase list size by +1
	this->incrementSize();

}

//Params: int index = index in list
//Returns: Planet * of the Planet at the index in the list
Planet * List::read(int index){
	if(this->size() == 0){ return NULL;}
	if(index > this->size() - 1){ return NULL;}

	if(index == 0){ return this->head->planet;}

	Node * temp = this->head;
	int i;

	//set temp to node at index
	for(i = 0; i < index; i++){
		temp = temp->next;
	}
	return temp->planet;
}

//Params: int index = index in list
//Deletes Element from index, decreasing size of List by 1
//Returns: true on successful deletion, false otherwise
bool List::remove(int index){
	Node * temp = this->head;
	int i;
	
	//Check if index is in List
	if(index > this->size() -1){
	       	std::cout << "Index is out of lists bounds" << std::endl;
		return false;
	}

	//if head is being deleted
	if(index == 0){
		this->head = this->head->next;
		delete temp;
		this->decrementSize();
		return true;
	}
	

	//set temp to appropriate node
	Node * toDelete = NULL;
	for(i = 0; i < index - 1; i++){
		temp = temp->next;
	}
	toDelete = temp->next;
	temp->next = toDelete->next;
	delete toDelete;

	//decrement list size
	this->decrementSize();
	
	return true;
}

//################################################################
//###############################################################
//Implementation of Node Class Methods

Node::Node(){
	this->next = NULL;
}

Node::~Node(){
	delete this->planet;
}
