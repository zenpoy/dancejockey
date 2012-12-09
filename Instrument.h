#pragma once
#include "Jockey.h"

class Instrument{};

class CirclePainter : Instrument {

public:

	CirclePainter() : _radiusChangeRate(0.005), _initRadius(10)
	{
		_radius = _initRadius;
		_wantedRadius = _initRadius;
	};

	void setup()
	{
		registerJockeyVelocityEvents(this);
	}
	
	void update();
	void draw();

	void velocityUpdate(float& velocity);
private:
	float _radius;
	float _wantedRadius;
	float _radiusChangeRate;
	float _initRadius;
};
