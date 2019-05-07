//
//  main.cpp
//  Assignment 7 - Binary Search Trees
//
//  Created by Akarsh Kumar on 4/21/19.
//  Copyright © 2019 Akarsh Kumar. All rights reserved.
//

#include <iostream>
#include "BST312.h"

using namespace std;

int main(int argc, const char * argv[]) {
    
    BST_312<int> tree;
    
    tree.insertItem(3);
    tree.insertItem(-3);
    tree.insertItem(9);
    tree.insertItem(5);
    tree.insertItem(100);
    tree.insertItem(0);
    tree.insertItem(-1);
    
    
    
    vector<int> vec = tree.inOrderTraversal();
    
    
    for(auto it = vec.begin(); it!=vec.end(); it++){
        cout << *it << endl;
    }
    cout<<tree.isItemInTree(9)<<endl;
    
    
    tree.makeEmpty();
    tree.
    
    vec = tree.inOrderTraversal();
    
    for(auto it = vec.begin(); it!=vec.end(); it++){
        cout << *it << endl;
    }
    
    
    return 0;
}
