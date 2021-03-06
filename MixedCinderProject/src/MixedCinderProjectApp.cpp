#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class MixedCinderProjectApp : public AppBasic {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
};

void MixedCinderProjectApp::setup()
{
}

void MixedCinderProjectApp::mouseDown( MouseEvent event )
{
}

void MixedCinderProjectApp::update()
{
}

void MixedCinderProjectApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) ); 
}

CINDER_APP_BASIC( MixedCinderProjectApp, RendererGl )
