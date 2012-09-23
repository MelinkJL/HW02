#include "Node.h"


Node::Node(void)
{
}


Node::~Node(void)
{
}

void insertAfter(Node* insert_me, Node* after_this)
{
	insert_me -> next_ = after_this -> next_;
	after_this -> next_ = insert_me;
	insert_me -> prev_ = after_this;
	insert_me -> next_ -> prev_ = insert_me;

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