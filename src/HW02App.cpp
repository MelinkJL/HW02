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
	
	font = new Font("Arial", 30);
	sentinel = new Node(0,0,0);
	Node* previous = sentinel;
	Node* cur;

	
	for(int i = 0; i < 20; i++){
		cur = new Node(100+(7*i),100+(7*i),100+(7*i));
		((Node)*cur).insertAfter(cur, previous);
		drawRect(myPixels_, cur -> x, cur -> x + cur -> radius, cur -> y, cur -> y + cur -> radius);
		previous = cur;
	}

	//sentinel->reverseList(sentinel);
	//cur = sentinel;
	
	
	//for(int x = 0; x < 7; x++){
	//	drawRect(myPixels_, cur -> x, cur -> x + cur -> radius, cur -> y, cur -> y + cur -> radius);
	//	cur = cur->next_;
	//}

}

void HW02App::mouseDown( MouseEvent event )
{
	
}
void HW02App::keyDown( KeyEvent event )
{
	
}

void HW02App::update()
{
	
}

void HW02App::draw()
{
	
	gl::draw(*mySurface_);
	//gl::drawString("hello world",Vec2f(200.0f,200.0f),Color(0.9f,0,0),*font);
	
	
}

CINDER_APP_BASIC( HW02App, RendererGl )
