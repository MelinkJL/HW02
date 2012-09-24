#include "Node.h"

Node::Node(int x1, int y1, int radius1)
{
	next_ = prev_ = this;
	
	x = x1;
	y = y1;
	radius = radius1;
}


void Node::insertAfter(Node* insert, Node* sentinel)
{
	insert->next_ = sentinel;
	insert->prev_ = sentinel->prev_;
	sentinel->prev_->next_ = insert;
	sentinel->prev_ = insert;
}

void Node::reverseList(Node* sentinel)
{
	Node* cur = sentinel;
	do{
		Node* temp = cur -> next_;
		cur -> next_ = cur -> prev_;
		cur -> prev_ = temp;
		cur = cur -> prev_;
	} while(cur != sentinel);
}