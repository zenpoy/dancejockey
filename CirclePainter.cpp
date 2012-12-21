#include "CirclePainter.h"
#include "ofGraphics.h"
#include "ofAppRunner.h"

void CirclePainter::update()
{
	//interpolate current into wanted
	_radius.value = ofLerp(_radius.value, _radius.target, _radius.changeRate);
	_radius.target = ofLerp(_radius.target, _radius.init, _radius.changeRate);
}

void CirclePainter::draw()
{
	ofPushMatrix();
	ofPushStyle();
	ofSetColor(255, 0, 0);

	_fill ? ofFill() : ofNoFill();

	ofPoint screenCenter(ofGetWindowWidth() / 2, ofGetWindowHeight() / 2);
	ofTranslate(screenCenter);
	ofCircle(ofPoint(), _radius.value);

	ofPopStyle();
	ofPopMatrix();
}

void CirclePainter::velocityUpdate( float& velocity )
{
	_radius.target += velocity; 
}

void CirclePainter::beat(Beat&)
{
	_fill = !_fill;
}