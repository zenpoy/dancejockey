#pragma once

#include "Jockey.h"
#include "ofThread.h"

class HandJockey : public ofThread, public Jockey
{
public:
	void setup();
	void exit();

	//std::deque<ofPoint> positionHistory() const { return _positionHistory; }
	//unsigned int historySize() const { return _historySize; }

protected:
	virtual void threadedFunction();

private:
	//std::deque<ofPoint> _positionHistory;
	//unsigned int _historySize;
};


