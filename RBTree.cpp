//
//  RBTree.cpp
//  practice
//
//  Created by Anant Srivastava on 12/20/18.
//  Copyright © 2018 Anant Srivastava. All rights reserved.
//

#include "RBTree.hpp"

void rbt::RBTree::left_rotate(Node * x) {
    Node * y = x->right;
    x->right = y->left;
    if(y->left != this.nil)
        y->left->parent = x;
    y->parent = x->parent;
    if(x->parent == this.nil)
        this.root = y;
    else if(x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;
    y->left = x;
    x->parent = y;
}

void rbt::RBTree::right_rotate(Node * y) {
    Node * x = y->left;
    y->left = x->right;
    if(x->right != this.nil)
        x->right->parent = y;
    x->parent = y->parent;
    if (y->parent == this.nil)
        this.root = x;
    else if(y == y->parent->left)
        y->parent->left = x;
    else
        y->parent->right = x;
    x->right = y
    y->parent = x;
}
