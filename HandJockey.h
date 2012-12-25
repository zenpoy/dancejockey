#pragma once

#include "ofThread.h"
#include "Instrument.h"

class HandJockey : public ofThread, public Instrument
{
public:
	virtual void setup();
	virtual void exit();

protected:
	virtual void threadedFunction();


};


