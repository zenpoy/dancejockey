#include "ScreenDebugPainter.h"
#include "ofGraphics.h"



void ScreenDebugPainter::update()
{

}

void ScreenDebugPainter::draw()
{
	fbo.end();
	ofClear(0);
	ofSetColor(ofColor::red);
	ofCircle(ofPoint(199, 19), 10);

	fbo.draw(0,0);
	fbo.begin();
}

void ScreenDebugPainter::velocityUpdate( float& velocity )
{
	
	ofSetColor(ofColor::yellow);
	ofCircle(ofPoint(199, 199), 10);
}
