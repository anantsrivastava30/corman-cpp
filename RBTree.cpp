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
    
    if(y->left != this->nil)
        y->left->parent = x;
    y->parent = x->parent;
    
    if(x->parent == this->nil)
        this->root = y;
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
    
    if(x->right != this->nil)
        x->right->parent = y;
    
    x->parent = y->parent;
    
    if (y->parent == this->nil)
        this->root = x;
    else if(y == y->parent->left)
        y->parent->left = x;
    else
        y->parent->right = x;
    x->right = y;
    y->parent = x;
}

void rbt::RBTree::rb_insert(int value) {
    rbt::Node * z = new rbt::Node(value);
    rbt::Node * x = this->root;
    rbt::Node * y = this->nil;
    while (x != this->nil) {
        y = x;
        if (z->val < x->val)
            x = x->left;
        else
            x = x->right;
    }
    z->parent = y;
    if (y == this->nil)
        this->root = z;
    else {
        if (z->val < y->val)
            y->left = z;
        else
            y->right = z;
    }
    z->left = this->nil;
    z->right = this->nil;
    // default color is red
    z->color = 0;
    rbt::RBTree::rb_insert_fixup(z);
}

void rbt::RBTree::rb_insert_fixup(rbt::Node * z) {
    while (z->parent != this->nil && z->parent->color == 0) {
        if (z->parent == z->parent->parent->left) {
            Node * y = z->parent->parent->right;
            if (y->color == 0) {
                z->parent->color = 1;
                y->color = 1;
                z->parent->parent->color = 0;
                z = z->parent->parent;
            }
            else {
                if (z == z->parent->right) {
                    z = z->parent;
                    rbt::RBTree::left_rotate(z);
                }
                z->parent->color = 1;
                z->parent->parent->color = 0;
                rbt::RBTree::right_rotate(z->parent->parent);
            }
        }
        else {
            Node * y = z->parent->parent->left;
            if (y->color == 0) {
                z->parent->color = 1;
                y->color = 1;
                z->parent->parent->color = 0;
                z = z->parent->parent;
            }
            else {
                if (z == z->parent->left) {
                    z = z->parent;
                    rbt::RBTree::right_rotate(z);
                }
                z->parent->color = 1;
                z->parent->parent->color = 0;
                rbt::RBTree::left_rotate(z->parent->parent);
            }
        }
    }
    this->root->color = 1;
}

void rbt::RBTree::rb_inorder(Node *node, int indent) {
    if(node == nullptr)
        return;
    else {
        rbt::RBTree::rb_inorder(node->right, indent + 4);
        if(node->val != -1)
            std::cout << std::string(indent , ' ' ) << "(" <<
                node->val << "," << node->color << ")" << std::endl;
        rbt::RBTree::rb_inorder(node->left, indent + 4);
    }
}
