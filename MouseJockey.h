#pragma once
#include "jockey.h"
#include <deque>

class MouseJockey : Jockey
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
