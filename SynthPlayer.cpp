#include "SynthPlayer.h"


void SynthPlayer::handUpdate( TrackedPoint& p )
{
	synth.setSpeed(ofMap(p.pos.y,-500.0, 500.0, 0.2, 4.0, true));
//		synth.setPan(ofMap(x, 0, widthStep, -1, 1, true));
}

void SynthPlayer::onGesture(bool& b)
{
	if (!synth.getIsPlaying())
	{
		synth.play();
	}
}
