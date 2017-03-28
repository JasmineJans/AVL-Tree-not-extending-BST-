//
//  AVLNode.h
//  NODE class for the AVLTree that has an extra field of not
//  just item and left and right children but also height.
//  Assignment7
//
//  Created by Jasmine Jans on 4/14/14.
//  Copyright (c) 2014 Jasmine Jans. All rights reserved.
//

#include <cstddef>
#ifndef Assignment7_AVLNode_h
#define Assignment7_AVLNode_h

typedef int ItemType;
class AVLNode
{
private:
    
    // creates a node
    // post: the item of the node is empty and the kids are NULL
    // usage: newptr = new cnode();
    AVLNode():mleftptr(NULL),mrightptr(NULL), height(0)  {};
    
    // creates a node with a given item and kids
    // post: the item of the node is nodeItem, the kids are left and right
    // usage:aptr = new (nothrow) Node (thisone, NULL, NULL);
    // CAUTION: REQUIRES THAT COPY WORKS IN ItemType!!
    AVLNode (const ItemType& nodeItem, AVLNode* left, AVLNode* right):
          mitem (nodeItem), mleftptr (left), mrightptr (right), height(0) {}
    
    // implementation of data object
    //ItemType mitem;
    int height;
    ItemType mitem;
    AVLNode* mleftptr;
    AVLNode* mrightptr;
    
    //friend functions
    friend class AVLTree;

};
#endif
