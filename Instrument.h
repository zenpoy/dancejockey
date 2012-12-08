#pragma once
#include "Jockey.h"

class Instrument{};

class CirclePainter : Instrument {

public:

	CirclePainter() : _circleRadius(10){};

	void setup()
	{
//		ofAddListener(JockeyEvents().velocityUpdate, this, &CirclePainter::velocityUpdate);
		registerJockeyVelocityEvents(this);
	}
	
	float CircleRadius() const { return _circleRadius; }
	void CircleRadius(float val) { _circleRadius = val; }
	void draw();

	void velocityUpdate(float& velocity);
private:
	float _circleRadius;

};
