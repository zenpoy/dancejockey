#pragma once
#include "ofEvents.h"
#include <deque>

class Jockey {};

class MouseJockey
{

public:
	MouseJockey() : _historySize(2) {
	}

	void setup()
	{
		ofRegisterMouseEvents(this);
	}

	void mouseMoved(ofMouseEventArgs&);
	void mouseDragged(ofMouseEventArgs&){};
	void mousePressed(ofMouseEventArgs&){};
	void mouseReleased(ofMouseEventArgs&){};


	std::deque<ofPoint> positionHistory() const { return _positionHistory; }
	unsigned int historySize() const { return _historySize; }

private:
	std::deque<ofPoint> _positionHistory;
	unsigned int _historySize;
};

class JockeyEvents{
public:
	ofEvent<float> velocityUpdate;
	//TODO: more events here...
};

JockeyEvents& getJockeyEvents();

//JockeyEvents voidEventArgs;

template<class ListenerClass>
void registerJockeyVelocityEvents(ListenerClass * listener){
	ofAddListener(getJockeyEvents().velocityUpdate, listener, &ListenerClass::velocityUpdate);
}