#pragma once
#include "jockey.h"
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

