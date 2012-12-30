#pragma once
#include "Jockey.h"
#include "Instrument.h"

#include <deque>

class GestureJockey : public Instrument
{
public:
	
	virtual void setup()
	{
		registerHandJockeyEvents(this);
		_historySize = 30;
	}

	virtual void draw3D();

	void handUpdate(TrackedPoint& p);

private:
	ofMutex mutex;
	std::deque<TrackedPoint> _positionHistory;	
	unsigned int _historySize;

	ofPoint sum;
	ofPoint avg;
	float avgSqrDist;

};

