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
        bool color;
        Node * left;
        Node * right;
        Node * parent;
        Node(int x) : val(x), left(nullptr), right(nullptr), parent(nullptr) {};
    };
    
    class RBTree {
    public:
        Node * root;
        Node * nil = nullptr;
        
        RBTree() : root(nullptr) {};
        ~RBTree() {};
        
        void left_rotate(Node * x) {};
        void right_rotate(Node * x) {};
    };
} // namespace rbt


#endif /* RBTree_hpp */
