//
//  bst.hpp
//  practice
//
//  Created by Anant Srivastava on 12/15/18.
//  Copyright © 2018 Anant Srivastava. All rights reserved.
//

#ifndef bst_hpp
#define bst_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <iomanip>

template <typename T>
struct Node {
    T val;
    Node * left;
    Node * right;
    Node(T x) : val(x), left(nullptr), right(nullptr) {}
};

template <typename T>
class BST{
public:
    Node<T> *root;

    BST() : root(nullptr) {};
    ~BST() {};
    
    void insert(T key);
    T head();
    void inorder(Node<T> *root, int indent);
    Node<T>* search(T val, Node<T> * &parent);
    void del(T z);
    void print(Node<T> * x, int & id);
    Node<T>* tree_min(Node<T> *node);
    void transplant(Node<T> * u, Node<T> * u_p, Node<T> * v);
    
};

#endif /* bst_hpp */
