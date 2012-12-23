#pragma once
#include "Instrument.h"
#include <deque>

#include "ofUtils.h"

class Metronome : Instrument
{
public:
	Metronome() :  _historySize(3)
	{
	}

	  void update();
	  void draw();

	  void setup()
	  {
		  registerJockeyBangEvents(this);
		  _tempo.setTimeStamp(ofGetSystemTime());
	  }

	  void velocityUpdate(float& velocity);
	  void bang(unsigned long long&);


private:

	Tempo _tempo;

	std::deque<unsigned long long> _bangHistory;
	std::deque<unsigned long long> _IntervalHistory;

	unsigned int _historySize;
};


