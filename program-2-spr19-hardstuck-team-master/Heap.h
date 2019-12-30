#ifndef HEAP_H
#define HEAP_H
#include <vector>
#include <cstdlib>
#include <iostream>
#include <algorithm>
template <class T>
class Heap{

	private:
		std::vector <T> heap;
		unsigned int left(unsigned int parent){ 
					return (((2*parent)+1 )< heap.size()) ? ((2*parent) +1): -1; 
				}
		unsigned int right(unsigned int parent){
					return (((2*parent)+2) < heap.size()) ? ((2*parent) +2): -1;
				}
		//unsigned int parent(unsigned int child) { 
					//return (child>0) ? (child-1)/2 : -1;
				//}
		void Heapify();
		void Siftdown(int i);
		bool isLeaf(int i);
		void Swap(int first, int second);
	public:
		Heap(){};
		Heap(std::vector<T>);
		void addElement(T element);
		T getPriority();
		bool empty() { return heap.empty(); }
		unsigned long size() { return heap.size(); }
		std::vector <T> getArray() { return this->heap;}

};
template <class T>
Heap<T>::Heap(std::vector <T> list){
	heap = list;
	Heapify();
}

template <class T>
bool Heap<T>::isLeaf(int i){
	if(left(i) == -1 && right(i) == -1) return true;
	else return false;

}

template <class T>
void Heap<T>::Swap(int first, int second){
	T temp = heap[first];
	heap[first] = heap[second];
	heap[second] = temp;
}

template <class T>
void Heap<T>::Heapify(){
	for(int i = (heap.size()-2)/2; i >= 0; i--){
		Siftdown(i);
	}
}

template <class T>
void Heap<T>::Siftdown(int i){
	while(!isLeaf(i)){
		int n = left(i);
		if(n == -1) n = right(i);
		else if(right(i) != -1 && heap[left(i)] < heap[right(i)]) n=right(i); //if index is valid
		if(heap[i] > heap[n]) return;
		Swap(i, n);
		i = n;
	}
}

template <class T>
void Heap<T>::addElement(T element){
	heap.push_back(element);
	Heapify();
}

template <class T>
T Heap<T>::getPriority(){
	T ret = heap[0];
	heap.erase(heap.begin());
	Heapify();
	return ret;
}



#endif
