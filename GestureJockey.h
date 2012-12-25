#pragma once
#include "jockey.h"
#include <deque>
#include "Instrument.h"

class GestureJockey : public Instrument
{
public:
	
	virtual void setup()
	{
		registerHandJockeyEvents(this);
		_historySize = 10;
	}

	virtual void draw3D();

	void handUpdate(ofPoint& p);

private:
	ofMutex mutex;
	std::deque<ofPoint> _positionHistory;
	unsigned int _historySize;
};

