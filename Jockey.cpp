#include "Jockey.h"


void MouseJockey::mouseMoved(ofMouseEventArgs& e)
{
	//raw event input
	_positionHistory.push_front(ofPoint(e.x,e.y));
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

JockeyEvents& getJockeyEvents()
{
	static JockeyEvents* events = new JockeyEvents;
	return *events;
}
