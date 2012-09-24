#include "Node.h"

Node::Node(int x1, int y1, int radius1)
{
	next_ = prev_ = this;
	
	x = x1;
	y = y1;
	radius = radius1;
}


void insertAfter(Node* insert_me, Node* after_this)
{
	(insert_me->next_) = after_this->next_; // insert_me points to the next node
	after_this->next_ = insert_me;         // after_this points to insert_me
	insert_me->prev_ = after_this;         // 
	insert_me->next_->prev_ = insert_me;

}

void reverseList(Node* sentinel)
{
	Node* cur = sentinel;
	do{
		Node* temp = cur -> next_;
		cur -> next_ = cur -> prev_;
		cur -> prev_ = temp;
		cur = cur -> prev_;
	} while(cur != sentinel);
}