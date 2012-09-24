#include "Node.h"

Node::Node(int x1, int y1, int radius1)
{
	next_ = prev_ = this;
	
	x = x1;
	y = y1;
	radius = radius1;
}


void Node::insertAfter(Node* insert_me, Node* after_this)
{
	insert_me->next_ = after_this->next_;
	insert_me->prev_ = after_this;
	after_this->next_ = insert_me;
	after_this->next_->prev_ = insert_me;
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