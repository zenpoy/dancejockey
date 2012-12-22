#include "CirclePainter.h"
#include "ofGraphics.h"
#include "ofAppRunner.h"

void CirclePainter::update()
{
	//interpolate current into wanted
	_radius.value = ofLerp(_radius.value, _radius.target, _radius.changeRate);
	_radius.target = ofLerp(_radius.target, _radius.init, _radius.changeRate);

	////TODO: move this to Beat, or Tempo or timeUtils.
	//unsigned long long now = ofGetSystemTime();
	//float diffSec = float(now - _beat.getTimeStamp()) / 1000.0f;
	//float progress = (diffSec / _tempo.getBeatLength());
	_theta = _progress * TWO_PI;

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

void CirclePainter::tempo(Tempo& t)
{
	//printf("tempo bpm: %f\n", t.getBpm());
	_tempo = t;
}


void CirclePainter::beat(Beat& beat)
{
	//printf("beat t:%d\n", beat.getTimeStamp());
	_beat = beat;
	_fill = !_fill;
}

void CirclePainter::click(float& level)
{
	//printf("beat t:%d\n", beat.getTimeStamp());
	_progress = level;
	_fill = !_fill;
}