#pragma once
#include "Instrument.h"
#include <deque>

class MouseJockey : public Instrument
{

public:
	MouseJockey() : _historySize(2) {
	}

	virtual void setup()
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
