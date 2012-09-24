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
};

void HW02App::drawRect(uint8_t* pixels, int x1, int x2, int y1, int y2){

	Color8u c = Color8u(0,0,0);

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
	srand(time(0));
	mySurface_ = new Surface(kSurfaceSize, kSurfaceSize, false);

	Node* previous = sentinel;
	Node* cur;

	sentinel = new Node(100, 100, 100);
	for(int i = 0; i < 7; i++){
		cur = new Node((rand()%200 + 10),(rand()%200 + 10),(rand()%200 + 10));
		((Node)*cur).insertAfter(cur, previous);
		previous = cur;
	}
}

void HW02App::mouseDown( MouseEvent event )
{
}

void HW02App::update()
{
	myPixels_ = (*mySurface_).getData();
	drawRect(myPixels_, sentinel -> x, sentinel -> x + sentinel -> radius, sentinel -> y, sentinel -> y + sentinel -> radius);
}

void HW02App::draw()
{
	gl::draw(*mySurface_);
}

CINDER_APP_BASIC( HW02App, RendererGl )
