//
//  main.cpp
//  practice
//
//  Created by Anant Srivastava on 11/11/18.
//  Copyright © 2018 Anant Srivastava. All rights reserved.
//

#include <iostream>
#include <unordered_map>
#include <string>
#include "bst.hpp"
#include "RBTree.hpp"

using namespace std;

void bst(){
    BST<int> tree;
    tree.insert(11);
    tree.insert(2);
    tree.insert(14);
    tree.insert(1);
    tree.insert(7);
    tree.insert(15);
    tree.insert(5);
    tree.insert(8);

    //cout << tree.head() << endl;
    //cout << tree.root->val << endl;
    
    
    //    tree.inorder(tree.root);
    int i = 0;
    tree.inorder(tree.root, i);
    tree.del(18);
    cout << "------------" << endl;
    tree.inorder(tree.root, i);
    
}

void redblacktree() {
    rbt::RBTree rbtree;
    for (int i = 1; i <= 100; ++i) {
        rbtree.rb_insert(i);
    }
    //cout << rbtree.root->val << endl;
    rbtree.rb_inorder(rbtree.root, 0);
}

int main(int argc, const char * argv[]) {
//    bst();
    redblacktree();
    return 0;
}




