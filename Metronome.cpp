#include "Metronome.h"
#include "ofGraphics.h"

void Metronome::bang(unsigned long long& t)
{
	_bangHistory.push_back(t);
	if (_bangHistory.size() <= _bangHistorySize)
	{
		return;
	}
	else
	{
		_bangHistory.pop_front();
	}
}

void Metronome::update()
{
	//process bangs
	//SOLVE FLOAT vs. LONGLONG issue
	if (_bangHistory.size() > 1)
	{
		unsigned long long meanTime = 0;
		for (int i=1; i < _bangHistory.size(); i++)
		{
			unsigned long long diff = _bangHistory[i] - _bangHistory[i-1];
			meanTime += diff;
		}
		_frequency.value = meanTime / _bangHistory.size();
		printf("f: %d\n", _frequency.value);
	}

	_beatCountdown--;

	if (_beatCountdown > 1) {
		_isSendBeat = false;
	}

	if (_beatCountdown < 1)
	{
		_isSendBeat = true;
		_beatCountdown = _frequency.value;
		Beat beat;
		ofNotifyEvent(getJockeyEvents().beat, beat); //TODO send id
	}

}

void Metronome::draw()
{
	ofPushStyle();
	ofSetColor(0, 255, 128);
	ofRect(0, 0, _beatCountdown , 5);

	if (_isSendBeat) 
	{
		ofRect(100, 100, 100, 100);
	}

	ofPopStyle();
}