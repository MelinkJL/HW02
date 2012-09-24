#pragma once
#include "Shape.h"

class Node
{
public:

	Node(void);
	
	Node* next_;
	Node* prev_;
	Shape* rect;

	void insertAfter(Node* insertMe, Node* afterMe);
	void reverseList(Node* the_sentinel);
	
};

