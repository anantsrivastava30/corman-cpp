//
//  RBTree.hpp
//  practice
//
//  Created by Anant Srivastava on 12/20/18.
//  Copyright © 2018 Anant Srivastava. All rights reserved.
//

#ifndef RBTree_hpp
#define RBTree_hpp

#include <cstdio>
#include <iostream>

namespace rbt {
    struct Node {
        int val;
        // 0 : red
        // 1 : black
        bool color;
        Node * left;
        Node * right;
        Node * parent;
        Node(int x) : color(0), val(x), left(nullptr), right(nullptr), parent(nullptr) {};
    };
    
    class RBTree {
    public:
        Node * nil = new Node(-1);
        Node * root = nil;

        RBTree() {
            nil->color = 1;
        };
        ~RBTree() {};
        
        void left_rotate(Node * x);
        void right_rotate(Node * x);
        Node * rb_search(int value);
        Node * rb_min(Node * node);
        void rb_insert(int value);
        void rb_insert_fixup(Node * z);
        void rb_inorder(Node * node, int indent);
        void rb_transplant(Node * u, Node * v);
        void rb_delete(int value);
        void rb_delete_fixup(Node * x);
    };
} // namespace rbt


#endif /* RBTree_hpp */
