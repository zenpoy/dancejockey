#include "SynthPlayer.h"


void SynthPlayer::handUpdate( ofPoint& p )
{
	synth.setSpeed(ofMap(p.y,-500.0, 500.0, 0.2, 4.0, true));
//		synth.setPan(ofMap(x, 0, widthStep, -1, 1, true));
}

void SynthPlayer::onGesture(bool& b)
{

	if (!synth.getIsPlaying());// && translation > 100) 
	{
		synth.play();
	}
}
