#include "CirclePainter.h"
#include "ofGraphics.h"
#include "ofAppRunner.h"

void CirclePainter::update()
{
	//interpolate current into wanted
	_radius.value = ofLerp(_radius.value, _radius.target, _radius.changeRate);
	_radius.target = ofLerp(_radius.target, _radius.init, _radius.changeRate);

	_theta = _tempo.getBarProgress() * TWO_PI;

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

	ofPoint xy = ofPoint(cosf(_theta), sinf(_theta));
	ofPoint orbital = xy *_radius.value;
	ofCircle(orbital, _radius.value / 10);

	ofPopStyle();
	ofPopMatrix();
}

void CirclePainter::velocityUpdate( float& velocity )
{
	_radius.target += velocity; 
}

void CirclePainter::onTempoChange(Tempo& t)
{
	//printf("tempo bpm: %f\n", t.getBpm());
	_tempo = t;
}


void CirclePainter::onBeat(Tempo& t)
{
	_tempo = t;
	_fill = !_fill;
}