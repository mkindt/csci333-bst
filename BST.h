#ifndef __BST_H__
#define __BST_H__

#include "Node.h"
#include <string>
#include <vector>
#include <math.h>
using std::vector;


template <typename T>
class BST {
 private:
  Node<T>* root;
  void traversalPrint(Node<T>* root);

 public:
  BST<T>();
  ~BST<T>();

  bool find(T v);
  void remove(T v);
  void insert(T v);
  void print();
  void printTree();

};


#endif
