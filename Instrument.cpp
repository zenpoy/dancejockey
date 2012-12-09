#include "Instrument.h"
#include "ofGraphics.h"
#include "ofAppRunner.h"

void CirclePainter::update()
{
	//interpolate current into wanted
	_radius = ofLerp(_radius, _wantedRadius, _radiusChangeRate);
	_wantedRadius = ofLerp(_wantedRadius, _initRadius, _radiusChangeRate);

}
void CirclePainter::draw()
{
	ofPushStyle();
	ofSetColor(255, 0, 0);
	ofCircle(ofGetWindowWidth() / 2, ofGetWindowHeight() / 2, _radius);
	ofPopStyle();
}

void CirclePainter::velocityUpdate( float& velocity )
{
	_wantedRadius += velocity; 
}
