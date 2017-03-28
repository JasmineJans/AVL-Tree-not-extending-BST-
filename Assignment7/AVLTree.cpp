//
//  AVLTree.cpp
//  Assignment7
//
//  Created by Jasmine Jans on 4/14/14.
//  Copyright (c) 2014 Jasmine Jans. All rights reserved.
//

#include <iostream>
#include "AVLtree.h"
using namespace std;

//default constructor with no parameters
AVLTree::AVLTree(): mroot(NULL) {}

//constructor that takes one parameter, the root value
AVLTree::AVLTree(const ItemType& rootItem)
{
    mroot = new AVLNode(rootItem, NULL, NULL);
}

// releases the memory of a binary tree
// pre: object exists
// post: memory for the object has been released. object theoretically does not exist
//       but in practice, it is empty.
AVLTree:: ~AVLTree()
{
    destroyTree(mroot);
    cout<<"hi"<<endl;
}

//destructor helper method
void AVLTree::destroyTree (AVLNode*& treep)
{
    // do a postorder traversal
    if (treep != NULL)
    {
        destroyTree(treep->mleftptr);
        destroyTree(treep->mrightptr);
        treep = NULL;
    }
}

//@inserts a new item into the AVL search tree
//@pre: newItem has been assigned
//@post: if the newItem's key is not already in the tree
//       and there is memory available
//         then the newItem is added to the tree
//       else an exception is thrown
//@usage: insert(newitem)
void AVLTree:: insert(ItemType newItem)
{
    insertItem (mroot, newItem);
}

//@recursively inserts an item in the correct place
//@pre: treeptr is assigned. newItem is assigned.
//@post: inserts the newItem in the tree with treeptr's root.
//@usage: insertItem (mroot, mitem);
void AVLTree:: insertItem (AVLNode *& treeptr, const ItemType& newItem)
{
    if (treeptr == NULL)
    {
		treeptr = new AVLNode(newItem, NULL, NULL);
		treeptr->height = 0;
		return;
	}
	
    else if (newItem < treeptr->mitem)
    {
		insertItem(treeptr->mleftptr, newItem);
	}
    
    else
    {
		insertItem(treeptr->mrightptr, newItem);
	}
	
	calcHeight(treeptr);
	
	if (treeptr->mleftptr == NULL || treeptr->mrightptr == NULL)
    {
		if (treeptr->mleftptr == NULL)
        {
			if (treeptr->mrightptr->height > 0)
				leftRotation(treeptr);
		}
		else if (treeptr->mrightptr == NULL)
        {
			if (treeptr->mleftptr->height > 0)
				rightRotation(treeptr);
		}
	}
	else
    {
		if (treeptr->mrightptr->height + 1 < treeptr->mleftptr->height)
        {
			if (treeptr->mleftptr->mleftptr == NULL && treeptr->mleftptr->mrightptr != NULL)
				leftRotation(treeptr->mleftptr);
			else if (treeptr->mleftptr->mrightptr == NULL);
			else if (treeptr->mleftptr->mrightptr->height > treeptr->mleftptr->mleftptr->height)
				leftRotation(treeptr->mleftptr);
			rightRotation(treeptr);
		}
		
		else if (treeptr->mleftptr->height + 1 < treeptr->mrightptr->height)
        {
			if (treeptr->mrightptr->mrightptr == NULL && treeptr->mrightptr->mleftptr != NULL)
				rightRotation(treeptr->mrightptr);
			else if (treeptr->mrightptr->mleftptr == NULL);
			else if (treeptr->mrightptr->mleftptr->height > treeptr->mrightptr->mrightptr->height)
				rightRotation(treeptr->mleftptr);
			leftRotation(treeptr);
		}
	}
    
}

//helper method for the insert class that balances ther
//tree after something is inserted.
void AVLTree::rightRotation(AVLNode* k1)
{
    AVLNode* k2 = k1->mleftptr;
    k1->mleftptr = k2->mrightptr;
    k2->mrightptr = k1;
    k1 = k2;
    calcHeight(k1->mrightptr);
    calcHeight(k1);
}

//helper method for the insert class that balances ther
//tree after something is inserted.
void AVLTree::leftRotation(AVLNode* k2)
{
    AVLNode* k1 = k2->mrightptr;
    k2->mrightptr = k1->mleftptr;
    k1->mleftptr = k2;
    k2 = k1;
    calcHeight(k2->mleftptr);
    calcHeight(k2);
}

//method calculates the height of a node tempRoot
void AVLTree::calcHeight(AVLNode*& tempRoot)
{
	if (tempRoot->mleftptr == NULL && tempRoot->mrightptr == NULL)
		tempRoot->height = 0;
	else if(tempRoot->mrightptr == NULL)
		tempRoot->height = tempRoot->mleftptr->height + 1;
	else if(tempRoot->mleftptr == NULL)
		tempRoot->height = tempRoot->mrightptr->height + 1;
	else if(tempRoot->mleftptr->height > tempRoot->mrightptr->height)
		tempRoot->height = tempRoot->mleftptr->height + 1;
	else
		tempRoot->height = tempRoot->mrightptr->height + 1;
}

//printing method for testing purposes
void AVLTree::printTest()
{
    printRecursion(mroot, 0);
}

//helper method for the printTest() class
void AVLTree::printRecursion(AVLNode*& root, int spaces)
{
    if(root != NULL)
    {
        printRecursion(root->mrightptr, spaces+1);
        for(int i = 1; i <= spaces; i++)
            cout << "        ";
        cout<< root->mitem << " " << root->height << endl;
        printRecursion(root->mleftptr, spaces+1);
    }
}

//final print method that print the key and
//it's height in preorder
void AVLTree::finalPrint()
{
    preorder(mroot);
}

//helper for the final print method that runs a
//preorder traversal through the nodes and then
//prints out the item and height of each AVLnode.
void AVLTree::preorder(AVLNode* treep) const
{
    if (treep != NULL)
    {
        cout <<  "Key: " << treep -> mitem << "   Height: " << treep->height <<endl;
        preorder (treep -> mleftptr);
        preorder (treep -> mrightptr);
    }
}