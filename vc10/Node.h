#pragma once
class Node
{
public:

	Node(void);
	~Node(void);
	
	Node* next_;
	Node* prev_;

	void insertAfter(Node* insertMe, Node* afterMe);
	void reverseList(Node* the_sentinel);
	
};

