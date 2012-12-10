#pragma once
#include "Jockey.h"
#include <deque>

class Instrument{
public:
	virtual void update() {};
	virtual void draw() {};

protected:
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

};

class Metronome : Instrument {
public:

	Metronome() : _frequency(120, 0.01f), _bangHistorySize(12), _beatCountdown(100), _isSendBeat(false)
	{
	}

	void update();
	void draw();

	void setup()
	{
		registerJockeyBangEvents(this);
	}

	void velocityUpdate(float& velocity);
	void bang(JockeyEventArgs&);

private:
	Value<unsigned long long> _frequency;
	std::deque<unsigned long long> _bangHistory;
	unsigned int _bangHistorySize;
	unsigned long long _beatCountdown;
	bool _isSendBeat;
};

class CirclePainter : Instrument {

public:

	CirclePainter() : _radius(10, 0.01f)
	{
	};

	void update();
	void draw();

	void setup()
	{
		registerJockeyVelocityEvents(this);
	}

	void velocityUpdate(float& velocity);

private:
	Value<float> _radius;

};
