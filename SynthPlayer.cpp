#include "SynthPlayer.h"


SynthPlayer::SynthPlayer(void)
{
}


SynthPlayer::~SynthPlayer(void)
{
}


void SynthPlayer::handUpdate( ofPoint& p )
{
	if (!synth.getIsPlaying()) 
	{
		synth.play();
		synth.setSpeed(ofMap(p.y,-500.0, 500.0, 0.2, 4.0, true));
//		synth.setPan(ofMap(x, 0, widthStep, -1, 1, true));

	}


}
