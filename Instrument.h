#pragma once
#include "Jockey.h"
#include <deque>

class InstrumentEvents{};
class InstrumentEventArgs{};

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


class MetronomeEvents : InstrumentEvents
{
public:
	ofEvent<InstrumentEventArgs> beat;
};

template<class ListenerClass>
void registerMetronomeEvents(ListenerClass * listener){
	ofAddListener(Metronome::events.beat, listener, &ListenerClass::beat);
}

class Metronome : Instrument {
public:

	Metronome() : _frequency(120, 0.01f), _bangHistorySize(12), _beatCountdown(100), _isSendBeat(false)
	{
	}

	void update();
	void draw();

	static MetronomeEvents events;
	
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
		registerMetronomeEvents(this);		
	}

	void velocityUpdate(float& velocity);
	void beat(InstrumentEventArgs&);

private:
	Value<float> _radius;
	bool _fill;

};
