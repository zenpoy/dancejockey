#pragma once
#include "jockey.h"
#include <deque>

class GestureJockey : public Jockey
{
public:
	
	void setup()
	{
		registerHandJockeyEvents(this);
		_historySize = 10;
	}

	void handUpdate(ofPoint& p);

	std::deque<ofPoint> _positionHistory;
	unsigned int _historySize;
};

