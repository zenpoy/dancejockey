#include "Jockey.h"

JockeyEventArgs bangEventArgs;

void MouseJockey::mouseMoved(ofMouseEventArgs& e)
{
	//raw event input
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


	// example of processing: pointInverter


	//send Event

}

void MouseJockey::mousePressed( ofMouseEventArgs& )
{
	ofNotifyEvent(getJockeyEvents().bang, bangEventArgs); //TODO send id
}

JockeyEvents& getJockeyEvents()
{
	static JockeyEvents* events = new JockeyEvents;
	return *events;
}
