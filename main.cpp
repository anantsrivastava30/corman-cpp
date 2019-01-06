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
    tree.insert(12);
    tree.insert(5);
    tree.insert(18);
    tree.insert(2);
    tree.insert(1);
    tree.insert(9);
    tree.insert(15);
    tree.insert(19);
    tree.insert(13);
    tree.insert(17);
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
    
}

int main(int argc, const char * argv[]) {
//    bst();
    redblacktree();
    return 0;
}




