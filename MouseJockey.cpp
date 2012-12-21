#include "MouseJockey.h"
#include "ofUtils.h"

void MouseJockey::mouseMoved(ofMouseEventArgs& e)
{
	_positionHistory.push_front(ofPoint(float(e.x),float(e.y)));
	if (_positionHistory.size() <= _historySize)
	{
		return;
	}
	else
	{
		_positionHistory.pop_back();
	}

	//process

	// example: calculate speed
	ofPoint speed = _positionHistory.back() - _positionHistory.front();
	float velocity = speed.length();
	ofNotifyEvent(getJockeyEvents().velocityUpdate, velocity); //TODO send id
}

void MouseJockey::mousePressed( ofMouseEventArgs& )
{
	unsigned long long t = ofGetSystemTime();
	ofNotifyEvent(getJockeyEvents().bang, t); //TODO send id
}
