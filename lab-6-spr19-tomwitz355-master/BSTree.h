#ifndef BSTREE_H
#define BSTREE_H

#include <iostream>
#include <cstdlib>
#include <vector>

template <class T>
class BSTree{
private:
	class Node{
	public:
		T data;
		Node *parent;
		Node *left;
		Node *right;
		Node(T data, Node *parent){
			this->data = data;
			this->parent = parent;
			this->left = nullptr;
			this->right = nullptr;
		}
	};

	void removeLeaf(Node *node){
		if(node == this->root){
			std::cout << "made it here" << std::endl;
			root = nullptr;
		}
		else if(node == node->parent->left){
			node->parent->left = nullptr;
		}
		else{
			node->parent->right = nullptr;
		}
		delete(node);
		node = nullptr;
	}
	void copyHelper(Node *node){
		if(node == nullptr){
			return;
		}
		insert(node->data);
		copyHelper(node->left);
		copyHelper(node->right);
	}
	void sortHelper(std::vector<T> &list, Node *node){
		if(node != nullptr){
			sortHelper(list, node->left);
			list.push_back(node->data);
			sortHelper(list, node->right);
		}
	}
	void deleteHelper(Node *node){
		if(node != nullptr){
			deleteHelper(node->left);
			deleteHelper(node->right);
			if(node == root){
				removeLeaf(node);
			}
			else{
				remove(node->data);
			}
		}
	}
	Node *findNode(T val, Node * node){
		if(node == nullptr){
			return nullptr;
		}
		if(node->data == val){
			return node;
		}
		Node *temp = findNode(val, node->left);
		if(temp == nullptr){
			temp = findNode(val, node->right);
		}
		return temp;
	}
	void shortcircuit(Node * node){
		if(node == this->root){
			if(node->left != nullptr){
				node->left->parent = nullptr;
				this->root = node->left;
			}
			else{
				node->right->parent = nullptr;
				this->root = node->right;
			}
		}
		else if(node == node->parent->left){
			if(node->left != nullptr){
				node->parent->left = node->left;
				node->left->parent = node->parent;
			}
			else{
				node->parent->left = node->right;
				node->right->parent = node->parent;
			}
		}
		else{
			if(node->left != nullptr){
				node->parent->right = node->left;
				node->left->parent = node->parent;
			}
			else{
				node->parent->right = node->right;
				node->right->parent = node->parent;
			}
		}
		node->left = nullptr;
		node->right = nullptr;
		delete(node);
		node = nullptr;
	}
	Node *findRightMin(Node * node){
		if(node->left == nullptr){
			return node;
		}
		return findRightMin(node->left);
	}
	void promotion(Node * node){
		Node *temp = findRightMin(node->right);
		node->data = temp->data;
		if(temp->left == nullptr && temp->right == nullptr){
			removeLeaf(temp);
		}
		else{
			shortcircuit(temp);
		}
	}
	bool insertHelper(T val, Node *node){
		if(val < node->data){
			if(node->left == nullptr){
				node->left = new Node(val, node);
				return true;
			}
			else{
				insertHelper(val, node->left);
			}
		}
		else{
			if(node->right == nullptr){
				node->right = new Node(val, node);
				return true;
			}
			else{
				insertHelper(val, node->right);
			}
		}
	}

public:
	Node* root;
	BSTree(){
		this->root = nullptr;
	}

	BSTree(const BSTree &old_tree){
		this->root = nullptr;
		copyHelper(old_tree.root);
	}

	~BSTree(){
		deleteHelper(this->root);
	}

	bool empty(){
		if(this->root == nullptr){
			return true;
		}
		return false;
	}
	bool insert(T val){
		if(this->root == nullptr){
			this->root = new Node(val, nullptr);
			return true;
		}
		if(find(val)){
			return false;
		}
		return insertHelper(val, root);
	}
	bool find(T val){
		Node * node = findNode(val, root);
		if(node != nullptr){
			return true;
		}
		else{
			return false;
		}
	}
	void sortedArray(std::vector<T> &list){
		if(this->root != nullptr){
			sortHelper(list ,this->root);
		}
	}
	bool remove(T val){
		if(find(val) == false){
			return false;
		}
		Node *temp = findNode(val, this->root);
		if(temp->left == nullptr && temp->right == nullptr){
			removeLeaf(temp);
			return true;
		}
		else if(temp->left == nullptr || temp->right == nullptr){
			shortcircuit(temp);
			return true;
		}
		else{
			promotion(temp);
			return true;
		}

	}

};
#endif
