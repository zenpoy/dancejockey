#pragma once
#include "instrument.h"
#include "ofSoundPlayer.h"
#include "JockeyTypes.h"
#include "Metronome.h"
#include <vector>
#include <set>

/* 
* PhraseRecorder (BOSS RC20)
* http://www.loopers-delight.com/tools/RC20/rc20manual.pdf
*
*/
class PhraseRecorder :	public Instrument
{
public:

	void setup()
	{
	}


private:
	// level knob - output volume
	float _outVol;

	// volume of the guide tone
	float _guideVol; 
	// lights when the loop quantize function is activated
	bool _isLoopQuantize;

	// phrase select
	int _currentPhrase;
	bool isPhraseUsed(int phraseId);

	//inst knob - inst jack input volume
	float _inVol;

	//reverse button - playback the phrase in reverse
	void reverseButton();

	//tempo button - set the tempo by the interval at which you press the button
	void tempoButton(Tempo& t);

	//save button - save the current phrase to internal memory
	void saveButton();

	// delete the content of the current phrase
	void deleteButton();

	// cancel button - halt write or delete operation (not sure is necessary)
	void cancelButton();

	// auto start button - start recording when audio comes in
	bool _isAutoStart;
	void autoStartButton();

	// select the recording method
	void modeButton();

	// empty track: start recording->(stop recording) start playback->overdubbing
	// playback->overdubbing
	// cancel button deletes the unsaved track
	void leftPedal();
	void rightPedal();


	// Output (thrugh connection to screenInstrument, soundInstrument and other instruments):
	/*
	_recIndicator;
	_playIndicator;
	_overdubIndicator;
	*/






};

