//
//  bst.cpp
//  practice
//
//  Created by Anant Srivastava on 12/15/18.
//  Copyright © 2018 Anant Srivastava. All rights reserved.
//

#include "bst.hpp"

template<typename T>
T BST<T>::head() {
    return this->root->val;
}

template<typename T>
void BST<T>::insert(T key) {
    Node<T> *z = new Node<T>(key);
    Node<T> *y = nullptr;
    Node<T> *x = this->root;

    while (x != nullptr) {
        y = x;
        if (z->val < x->val)
            x = x->left;
        else
            x = x->right;
    }
    if (y == nullptr)
        this->root = z;
    else {
        if (z->val < y->val)
            y->left = z;
        else
            y->right = z;
    }
}

template<typename T>
void BST<T>::inorder(Node<T> *node, int indent) {
    if(node == nullptr)
        return;
    else {
        inorder(node->right, indent + 4);
        std::cout << std::string(indent , ' ' ) << node->val << std::endl;
        inorder(node->left, indent + 4);
    }
}

template<typename T>
Node<T>* BST<T>::search(T val, Node<T> * &parent) {
    Node<T> *x = this->root;
    parent = nullptr;
    
    while(x != nullptr && val != x->val) {
        parent = x;
        if (val < x->val)
            x = x->left;
        else
            x = x->right;
    }
    //std::cout << "value not found ..." << std::endl;
    return x;
}

template<typename T>
Node<T>* BST<T>::tree_min(Node<T> *node) {
    while(node->left != nullptr) {
        node = node->left;
    }
    return node;
}

template<typename T>
void BST<T>::transplant(Node<T> * u, Node<T> * u_p, Node<T> * v) {
    if (u_p == nullptr) {
        this->root = v;
    }
    else if (u_p->left == u) {
        u_p->left = v;
    }
    else if (u_p->right == u) {
        u_p->right = v;
    }
}

template<typename T>
void BST<T>::del(T val) {
//    if(z->right == nullptr)
    Node<T> *parent = nullptr;
    Node<T> *curr = search(val, parent);
    //std::cout << "current : " << curr->val << " parent : " << parent->val << std::endl;
    
    if (curr->left == nullptr) {
        transplant(curr, parent, curr->right);
    }
    else if (curr->right == nullptr) {
        transplant(curr, parent, curr->left);
    }
    else {
        Node<T> * successor = tree_min(curr->right);
        Node<T> * successor_p = nullptr;
        auto __ = search(successor->val, successor_p);
        if(curr->right != successor) {
            transplant(successor, successor_p, successor->right);
            successor->right = curr->right;
        }
        transplant(curr, parent, successor);
        successor->left = curr->left;
        delete curr;
    }
}

template class BST<int>;

