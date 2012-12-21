#pragma once
#include "Instrument.h"

class CirclePainter : Instrument
{

public:

	CirclePainter() : _radius(10, 0.01f), _theta(0.0f)
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
	void tempo(Tempo& b);

private:

	float _theta;

	Tempo _tempo;
	Beat _beat;

	Value<float> _radius;
	bool _fill;
};
