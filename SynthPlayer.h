#pragma once
#include "instrument.h"
#include "ofSoundPlayer.h"

class SynthPlayer :
	public Instrument
{
public:
	SynthPlayer(void);
	~SynthPlayer(void);
	
	void setup()
	{
		registerHandJockeyEvents(this);

		system("dir");
		synth.loadSound("sounds\\synth.wav");
		synth.setVolume(0.75f);
	}

	void handUpdate(ofPoint& p);

private:
	ofSoundPlayer  synth;

};

