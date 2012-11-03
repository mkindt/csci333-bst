#include "BST.h"
#include <iostream>
#include <vector>
#include <math.h>
using std::vector;


template <typename T>
BST<T>::BST() {
  root = 0;
}

template <typename T>
BST<T>::~BST() {
  
}


template <typename T>
bool BST<T>::find(T v) {
  Node<T>** curr = &root;
  while (*curr != 0 && (*curr)->getValue() != v) {
    if (v < (*curr)->getValue()) {
      curr = &((*curr)->getLeftChild());
    } else if (v > (*curr)->getValue()) {
      curr = &((*curr)->getRightChild());
    }
  }
  if (*curr !=0)
	  return true;
  else
	  return false;
}

template <typename T>
void BST<T>::insert(T v) {
  Node<T>* temp = new Node<T>(v);
  Node<T>** curr = &root;

  while (*curr != 0) {
    if (v < (*curr)->getValue()) {
      curr = &((*curr)->getLeftChild());
    } else if (v > (*curr)->getValue()) {
      curr = &((*curr)->getRightChild());
    }
  }
  *curr = temp;
}

template <typename T>
void BST<T>::remove(T v) {
  Node<T>** curr = &root;
  while (*curr != 0 && (*curr)->getValue() != v) {
    if (v < (*curr)->getValue()) {
      curr = &((*curr)->getLeftChild());
    } else if (v > (*curr)->getValue()) {
      curr = &((*curr)->getRightChild());
    }
  }
  if (*curr == 0)
	  std::cout << "Cannot remove, not found." << std::endl;
  else{
	  if ((*curr)->getLeftChild() == 0)
		  *curr = (*curr)->getRightChild();
	  else if ((*curr)->getRightChild() == 0)
		  *curr = (*curr)->getLeftChild();
	  else{
		  Node<T>** recall = curr;
		  curr = &((*curr)->getLeftChild());
		  while (*curr != 0)
			  curr = &((*curr)->getRightChild());
		  *curr = (*recall)->getRightChild();
		  *recall = (*recall)->getLeftChild();
	  }
  }
}

template <typename T>
void BST<T>::print() {
  traversalPrint(root);
}

template <typename T>
void BST<T>::printTree() {
  vector<vector <Node<T>*> > PrintMe;
  PrintMe.push_back(vector<Node<T>*>());
  PrintMe[0].push_back(root);
  size_t countNulls = 0;
  int level = 0;
  while (countNulls != PrintMe[level].size()){
	  countNulls = 0;
	  PrintMe.push_back(vector<Node<T>*>());
	  double sizer = pow(2.0, level);
	  for (int i = 0; i < sizer; i++){
		  if (PrintMe[level][i] == 0){
			  PrintMe[level+1].push_back(0);
			  PrintMe[level+1].push_back(0);
			  countNulls = countNulls + 2;
		  }
		  else{
			  PrintMe[level+1].push_back(PrintMe[level][i]->getLeftChild());
			  PrintMe[level+1].push_back(PrintMe[level][i]->getRightChild());
		  }
	  }
	  level++;
	}
  double spaces;
	for (int k = 0; k < level; ++k){
		// max size divided by max number of gaps (max children+1) per level minus spacing of each value
		spaces = ((((level*12)-20) / ((pow (2.0, k))+1)) - 1); 
		for (int i = 0; i < spaces; ++i)
			std::cout << " ";
		for (size_t j = 0; j < PrintMe[k].size(); ++j){
			if (PrintMe[k][j] == 0)
				std::cout << " ";
			else if (j%2 != 0)
				std::cout << "\\";
			else
				std::cout << "/";
			for (int i = 0; i < spaces; ++i)
				std::cout << " ";
		}
		std::cout << std::endl;
		for (int i = 0; i < spaces; ++i)
			std::cout << " ";
		for (size_t j = 0; j<PrintMe[k].size(); ++j){
			if (PrintMe[k][j] == 0)
				std::cout << " ";
			else
				std::cout << PrintMe[k][j]->getValue();
			for (int i = 0; i < spaces; ++i)
			std::cout << " ";
		}
		std::cout << std::endl;
	}	
}

template <typename T>
void BST<T>::traversalPrint(Node<T>* root) {
  if(root != 0) {
    traversalPrint(root->getLeftChild());
    std::cout << root->getValue() << std::endl;
    traversalPrint(root->getRightChild());
  }
}

template class BST<int>;
template class BST<double>;
template class BST<std::string>;
