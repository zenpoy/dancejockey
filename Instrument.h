#pragma once
#include "Jockey.h"
#include <deque>

class Instrument{};

class CirclePainter : Instrument {

public:

	CirclePainter() : _radius(10, 0.01), _frequency(120, 0.01), _bangHistorySize(12)
	{
		
	};

	void setup()
	{
		registerJockeyVelocityEvents(this);
		registerJockeyBangEvents(this);
	}
	
	void update();
	void draw();

	void velocityUpdate(float& velocity);
	void bang(JockeyEventArgs&);

private:

	template <class T>
	struct Value
	{
		Value(T init, float changeRate) : init(init), changeRate(changeRate), value(init), target(init)
		{}
		T init;
		float changeRate;
		T value;
		T target;
	};

	Value<float> _radius;
	Value<unsigned long long> _frequency;


	std::deque<unsigned long long> _bangHistory;
	unsigned int _bangHistorySize;

};
