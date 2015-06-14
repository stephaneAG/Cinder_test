#include "cinder/Cinder.h"
#include "cinder/app/AppScreenSaver.h"
#include "cinder/Color.h"

using namespace ci;
using namespace ci::app;

class MixedCinderScreenSaverProjectApp : public AppScreenSaver {
 public:
	virtual void setup();
	virtual void update();
	virtual void draw();
	
 protected:
	ci::Color	mColor, mBackgroundColor;
	float		mRadius;
};


void MixedCinderScreenSaverProjectApp::setup()
{
	mColor = Color( 1.0f, 0.5f, 0.25f );
	mBackgroundColor = Color( 0.25f, 0.0f, 0.0f );
}

void MixedCinderScreenSaverProjectApp::update()
{
	mRadius = abs( cos( getElapsedSeconds() ) * 200 );
}

void MixedCinderScreenSaverProjectApp::draw()
{
	gl::clear( mBackgroundColor );
	glColor3f( mColor );
	gl::drawSolidCircle( getWindowCenter(), mRadius );
}


CINDER_APP_SCREENSAVER( MixedCinderScreenSaverProjectApp, RendererGl )
