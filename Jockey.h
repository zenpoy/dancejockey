#pragma once
#include "ofEvents.h"
#include <deque>

class Jockey {

public:
	Jockey() : _historySize(2) {
	}

	void setup()
	{
		ofAddListener(ofEvents().mouseMoved , this, &Jockey::mouseMoved);
		//	ofRegisterMouseEvents(this);
	}

	//void mouseMoved(int x, int y);
	void mouseMoved(ofMouseEventArgs&);

//	void mouseDragged(int x, int y, int button){};
//	void mousePressed(int x, int y, int button){};
//	void mouseReleased(int x, int y, int button){};


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