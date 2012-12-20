#pragma once
#include "instrument.h"
#include "ofSoundPlayer.h"

class SynthPlayer :	public Instrument
{
public:

	void setup()
	{
		registerHandJockeyEvents(this);
		registerGestureJockeyEvents(this);

		synth.loadSound("./sounds/synth.wav");
		synth.setVolume(0.75f);
		synth.play();

	}

	void handUpdate(ofPoint& p);
	void onGesture(bool& b);

private:
	ofSoundPlayer  synth;


};

