/* Data Object:
    An AVL Tree is a type of Binary search tree. It has all the same characteristics of
    a binary search tree but it adds the requirment that the tree must be balanced, meaning
    a nodes subtrees height cannot differ by more than 1.
 */
//  AVLTree.h
//  Assignment7
//
//  Created by Jasmine Jans on 4/14/14.
//  Copyright (c) 2014 Jasmine Jans. All rights reserved.
//

#ifndef Assignment7_AVLTree_h
#define Assignment7_AVLTree_h

#include "AVLnode.h"

class AVLTree
{
    public:
    
        //constructors and destructor
    
        //default constructor sets mroot to NULL.
        AVLTree();
        //constructor that sets mroot to rootItem
        //given through a parameter.
        AVLTree(const ItemType& rootItem);
        //destructor
        ~AVLTree();
    
        //testing and important functions
    
        //@inserts a new item into the AVL search tree
        //@pre: newItem has been assigned
        //@post: if the newItem's key is not already in the tree
        //       and there is memory available
        //         then the newItem is added to the tree
        //       else an exception is thrown
        //@usage: insert(item)
        void insert(ItemType newItem);
    
        //method that prints tree in a treelike form
        //and calls the method printRecursion with the
        //root of the AVL Tree
        //@pre: a tree to be printed exists.
        //@post: the tree is printed in a treelike form.
        //@usage: printTest()
        void printTest();
    
        //method that prints each node in the tress item and heigh
        //in preorder and calls the method preorder with the
        //root of the AVL Tree
        //@pre: a tree to be printed exists.
        //@post: the avlnodes heights and keys are all printed
        //in preorder.
        //@usage: finalPrint()
        void finalPrint();
    
    protected:
    
        // Releases memory for an AVLtree
        // pre: treep points to the root of an AVLtree
        // post: releases all of the nodes in the tree pointed to by treep
        //    and leaves treep empty.
        // usage: destroyTree (mroot);
        void destroyTree (AVLNode*& treep);
    
        //@recursively inserts an item into its correct place in the AVLtree
        //@pre: treeptr is assigned. newItem is assigned.
        //@post: inserts the newItem in the tree with treeptr's root.
        //@usage: insertItem (mroot, mitem);
        void insertItem (AVLNode* &treeptr, const ItemType& newItem);
    
        //@calculates the height of an AVLnode in the tree
        //@pre: an AVLNode mroot exists
        //@post: the height of mroot is assigned.
        //@usage: calcHeight(mroot);
        void calcHeight(AVLNode*& mroot);
    
        //helper method for the printTest() class
        //@pre: an AVLNode root exists.
        //@post: the tree is printed in a treelike form.
        //@usage: printRecursion(mroot, 0)
        void printRecursion(AVLNode*& root, int spaces);
    
        // helper method for the finalPrint function.
        // pre: treep points to the root of an AVLtree to be traversed
        // post: prints the item and height of the nodes in preorder
        // usage: preorder (mroot);
        void preorder(AVLNode* treep) const;
    
        // a balancing method used in InsertItem
        // pre: AVLnode k1 exists
        // post: nodes in the tree are rotated to the left
        // inorder to find a balanced position based on each
        // node's height.
        // usage: rightRotation(avlnode);
        void rightRotation(AVLNode* k1);
    
        // a balancing method used in InsertItem
        // pre: AVLnode k2 exists
        // post: nodes in the tree are rotated to the right
        // inorder to find a balanced position based on each
        // node's height.
        // usage: leftRotation(avlnode);
        void leftRotation(AVLNode* k2);
    
        //protected variable for the root of the tree
        AVLNode* mroot;
    
};

#endif
