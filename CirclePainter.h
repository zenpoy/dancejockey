#pragma once
#include "Instrument.h"

class CirclePainter : public Instrument
{

public:

	CirclePainter() : _radius(10, 0.05f), _theta(0.0f)
	{
	};


	virtual void setup()
	{
		registerJockeyVelocityEvents(this);
		registerMetronomeEvents(this);		
	}

	void velocityUpdate(float& velocity);

	void onTempoChange(Tempo& b);
	void onBeat(Tempo& level);

	virtual void update();
	virtual void draw2D();

private:

	float _theta;
	Tempo _tempo;

	Value<float> _radius;
	bool _fill;
};
