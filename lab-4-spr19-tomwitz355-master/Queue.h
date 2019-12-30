#ifndef QUEUE_H
#define QUEUE_H

#include "Vector.h"

template <class T>
class Queue{
private:
  Vector<T> *queue;
  unsigned int queue_size;
  unsigned int back;
public:
  Queue(unsigned int);
  ~Queue();
  bool enqueue(T data);
  T dequeue();
  T peek();
  bool empty();
  void clear();

};

template <class T>
Queue<T>::Queue(unsigned int size){
  this->queue = new Vector<T>(size);
  this->queue_size = size;
  this->back = 0;
}

  template <class T>
  Queue<T>::~Queue(){
    delete this->queue;
  }

template <class T>
bool Queue<T>::enqueue(T data){
  if(this->back < this->queue_size){
    this->queue->vector[this->back] = data;
    this->back++;
    return true;
  }
  return false;
}

template <class T>
T Queue<T>::dequeue(){
  T retval = this->queue->vector[0];
  for(int i = 0; i < this->queue_size-1;i++){
    this->queue->vector[i] = this->queue->vector[i+1];
  }
  this->queue[this->queue_size-1] = NULL;
  this->back--;
  return retval;
}

template <class T>
T Queue<T>::peek(){
  T retval = this->queue->vector[0];
  return retval;
}

template <class T>
bool Queue<T>::empty(){
  if(this->back == 0){
    return true;
  }
  return false;
}

template <class T>
void Queue<T>::clear(){
  for(int i = 0; i < this->queue_size; i++){
    this->queue->vector[i] = NULL;
  }
  this->back = 0;
}
#endif
