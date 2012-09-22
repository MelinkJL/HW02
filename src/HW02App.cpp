#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/gl/Texture.h"

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
	static const int kAppWidth = 600;
	static const int kAppHeight = 600;
	static const int kSurfaceSize = 1240;
	
  private:
	Surface* mySurface_;
	uint8_t* myPixels_;
};

void HW02App::prepareSettings(Settings* settings)
{
	settings->setWindowSize(kAppWidth, kAppHeight);
	settings->setResizable(false);
}

void HW02App::setup()
{
	mySurface_ = new Surface(kSurfaceSize, kSurfaceSize, false);
	myPixels_ = (*mySurface_).getData();
}

void HW02App::mouseDown( MouseEvent event )
{
}

void HW02App::update()
{
}

void HW02App::draw()
{
	gl::draw(*mySurface_);
}

CINDER_APP_BASIC( HW02App, RendererGl )
