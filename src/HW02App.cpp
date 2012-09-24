#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/gl/Texture.h"
#include "Node.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class HW02App : public AppBasic {
  public:
	void prepareSettings(Settings* settings);
	void setup();
	void mouseDown( MouseEvent event );	
	void keyDown( KeyEvent event );	
	void update();
	void draw();
	void drawRect(uint8_t* pixels, int x1, int x2, int y1, int y2);
	static const int kAppWidth = 600;
	static const int kAppHeight = 600;
	static const int kSurfaceSize = 1240;
	
  private:
	Surface* mySurface_;
	uint8_t* myPixels_;
	Node* sentinel;
	Font* font;
	bool menu;
};

void HW02App::drawRect(uint8_t* pixels, int x1, int x2, int y1, int y2){

	Color8u c = Color8u(x2,0,x1);

	int startx = (x1 < x2) ? x1 : x2;
	int endx = (x1 < x2) ? x2 : x1;
	int starty = (y1 < y2) ? y1 : y2;
	int endy = (y1 < y2) ? y2 : y1;
	// these determine which are the starting and ending points of the rectangle

	if(endx < 0)
		return; 
	if(endy < 0) 
		return; 
	if(startx >= kAppWidth) 
		return; 
	if(starty >= kAppHeight) 
		return;
	if(endx >= kAppWidth) endx = kAppWidth - 1;
	if(endy >= kAppHeight) endy = kAppHeight - 1;

	for(int y = starty; y < endy; y++){
		// starts from top
		for(int x = startx; x < endx; x++){
			// starts from the left and draws a horizontal line

		pixels[(3 * x) + (y * kSurfaceSize * 3 )] = c.r;
		pixels[(3 * x) + (y * kSurfaceSize * 3) + 1] = c.g;
		pixels[(3 * x) + (y * kSurfaceSize * 3) + 2] = c.b;
		}
	}
}

void HW02App::prepareSettings(Settings* settings)
{
	settings->setWindowSize(kAppWidth, kAppHeight);
	settings->setResizable(false);
}

void HW02App::setup()
{
	
	mySurface_ = new Surface(kSurfaceSize, kSurfaceSize, false);
	myPixels_ = (*mySurface_).getData();
	menu = true;
	font = new Font("Times New Roman", 25);
	sentinel = new Node(100,100,100);
	Node* previous = sentinel;
	Node* cur;

	
	for(int i = 0; i < 10; i++){
		cur = new Node(100+(7*i),100+(7*i),100+(7*i));
		((Node)*cur).insertAfter(cur, previous);
		previous = cur;
	}

}

void HW02App::mouseDown( MouseEvent event )
{
	if(event.isLeftDown()){
		sentinel->reverseList(sentinel);
		Node* cur = sentinel->next_;
		do{
			drawRect(myPixels_, cur -> x, cur -> x + cur -> radius, cur -> y, cur -> y + cur -> radius);
			cur = cur->next_;
		} while(cur != sentinel);
	}
}
void HW02App::keyDown( KeyEvent event )
{
	if(event.getChar() == '?')
		menu = !menu;
	if(event.isControlDown()){
		Node* current = sentinel->next_;
		sentinel->next_ = current->next_;
		sentinel->next_->prev_ = sentinel;
		sentinel->insertAfter(current, sentinel);
		do{
			drawRect(myPixels_, current -> x, current -> x + current -> radius, current -> y, current -> y + current -> radius);
			current = current->next_;
		} while(current != sentinel);
	}
}

void HW02App::update()
{
	
}

void HW02App::draw()
{
	if(menu){ 
		gl::clear(Color(0,0,0));
		gl::drawString("Click on the screen to display and reverse list of rectangles.",Vec2f(30.0f,350.0f),Color(0,0,1.0f),*font);
		gl::drawString("Click control button to scroll through the list(bring rectangle to top).",Vec2f(30.0f,275.0f),Color(0,0,1.0f),*font);
		gl::drawString("(click ? to go to screen with rectangles or to come back to these directions)",Vec2f(30.0f,200.0f),Color(0,0,1.0f),*font);
	}
	else
		gl::draw(*mySurface_);
	
}

CINDER_APP_BASIC( HW02App, RendererGl )
