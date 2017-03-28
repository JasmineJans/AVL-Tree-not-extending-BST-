//
//  main.cpp
//  Assignment7
//
//  Created by Jasmine Jans on 4/14/14.
//  Copyright (c) 2014 Jasmine Jans. All rights reserved.
//

#include "AVLtree.h"

int main()
{
	AVLTree avl = AVLTree(9);
    avl.insert(40);
	avl.insert(24);
	avl.insert(56);
	avl.insert(16);
	avl.insert(32);
	avl.insert(48);
	avl.insert(6);
	avl.insert(64);
	avl.insert(3);
	avl.insert(43);
	avl.insert(93);
	avl.insert(84);
	avl.insert(8);
	avl.insert(47);
	avl.insert(77);
	avl.insert(123);
	avl.insert(31);
    avl.finalPrint();
	avl.printTest();
}