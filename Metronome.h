#pragma once
#include "Instrument.h"
#include <deque>

class Metronome : Instrument
{
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
	void bang(unsigned long long&);


private:
	Value<unsigned long long> _frequency;
	std::deque<unsigned long long> _bangHistory;
	unsigned int _bangHistorySize;
	unsigned long long _beatCountdown;
	bool _isSendBeat;
};


