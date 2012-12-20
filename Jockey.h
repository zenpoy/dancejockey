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
	void mousePressed(ofMouseEventArgs&);
	void mouseReleased(ofMouseEventArgs&){};


	std::deque<ofPoint> positionHistory() const { return _positionHistory; }
	unsigned int historySize() const { return _historySize; }

private:
	std::deque<ofPoint> _positionHistory;
	unsigned int _historySize;
};

class JockeyEventArgs{};

class JockeyEvents{
public:
	ofEvent<float> velocityUpdate;
	ofEvent<JockeyEventArgs> bang;
	ofEvent<ofPoint> handUpdate;
	//TODO: more events here...
};

JockeyEvents& getJockeyEvents();


template<class ListenerClass>
void registerJockeyVelocityEvents(ListenerClass * listener){
	ofAddListener(getJockeyEvents().velocityUpdate, listener, &ListenerClass::velocityUpdate);
}

template<class ListenerClass>
void registerJockeyBangEvents(ListenerClass * listener){
	ofAddListener(getJockeyEvents().bang, listener, &ListenerClass::bang);
}

// helper function
template<class ListenerClass>
void registerHandTrackerEvents(ListenerClass * listener){
	ofAddListener(getTrackerEvents().handUpdate, listener, &ListenerClass::handUpdate);
}
