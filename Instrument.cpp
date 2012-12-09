#include "Instrument.h"
#include "ofGraphics.h"
#include "ofAppRunner.h"

void CirclePainter::update()
{
	//interpolate current into wanted
	_radius.value = ofLerp(_radius.value, _radius.target, _radius.changeRate);
	_radius.target = ofLerp(_radius.target, _radius.init, _radius.changeRate);

	//process bangs
	/*
	SOLVE FLOAT vs. LONGLONG issue
	if (_bangHistory.size() > 0)
	{
		unsigned long long meanTime = 0;
		for (int i=1; i < _bangHistory.size(); i++)
		{
			unsigned long long diff = _bangHistory[i] - _bangHistory[i-1];
			meanTime += diff;
		}
		meanTime /= _bangHistory.size();
	}
	*/
	//	_frequency.value = ofLerp(_radius.value, _radius.target, _radius.changeRate);



}
void CirclePainter::draw()
{
	ofPushStyle();
	ofSetColor(255, 0, 0);
	ofCircle(ofGetWindowWidth() / 2, ofGetWindowHeight() / 2, _radius.value);
	ofPopStyle();
}

void CirclePainter::velocityUpdate( float& velocity )
{
	_radius.target += velocity; 
}

void CirclePainter::bang( JockeyEventArgs& )
{
	_bangHistory.push_front(ofGetSystemTime());
	if (_bangHistory.size() <= _bangHistorySize)
	{
		return;
	}
	else
	{
		_bangHistory.pop_back();
	}
}
