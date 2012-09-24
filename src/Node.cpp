#include "Node.h"

Node::Node(int x1, int y1, int radius1)
{
	next_ = prev_ = this;
	
	x = x1;
	y = y1;
	radius = radius1;
}


void Node::insertAfter(Node* insert_me, Node* sentinel)
{
	insert_me->next_ = sentinel;
	insert_me->prev_ = sentinel->prev_;
	sentinel->prev_->next_ = insert_me;
	sentinel->prev_ = insert_me;
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