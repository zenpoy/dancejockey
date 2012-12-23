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

	void onTempoChange(Tempo& b);
	void onBeat(Tempo& level);

private:

	float _theta;
	Tempo _tempo;

	Value<float> _radius;
	bool _fill;
};
