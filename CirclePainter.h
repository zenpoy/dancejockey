#pragma once
#include "Instrument.h"

class CirclePainter : Instrument
{

public:

	CirclePainter() : _radius(10, 0.01f)
	{
	};

	void update();
	void draw();

	void setup()
	{
		registerJockeyVelocityEvents(this);
		registerMetronomeEvents(this);		
	}

	void velocityUpdate(float& velocity);
	void beat(Beat& b);

private:
	Value<float> _radius;
	bool _fill;
};
