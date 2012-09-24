#pragma once
#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/gl/Texture.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Node
{
public:

	Node(int x1, int y1, int radius1);
	
	Node* next_;
	Node* prev_;
	int x, y, radius;
	//Color8u c;

	void insertAfter(Node* insertMe, Node* afterMe);
	void reverseList(Node* the_sentinel);
	
};

