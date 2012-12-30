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

	virtual void draw2D();

private:
	ofMutex mutex;
	std::deque<TrackedPoint> _positionHistory;	
	unsigned int _historySize;

	ofPoint sum;
	ofPoint avg;

	float sumDistAvg;
	float avgDistAvg;
	float minDistAvg;
	float maxDistAvg;

	float circlePredictionFactor;

};

