#include "Instrument.h"
#include "ofGraphics.h"
#include "ofAppRunner.h"

void CirclePainter::update()
{
	//interpolate current into wanted
	_radius.value = ofLerp(_radius.value, _radius.target, _radius.changeRate);
	_radius.target = ofLerp(_radius.target, _radius.init, _radius.changeRate);

}
void CirclePainter::draw()
{
	ofPushStyle();
	ofSetColor(255, 0, 0);
	ofCircle(ofGetWindowWidth() / 2, ofGetWindowHeight() / 2, _radius.value);
	ofPopStyle();
}

void CirclePainter::velocityUpdate( float& velocity )
{
	_radius.target += velocity; 
}

void Metronome::bang( JockeyEventArgs& )
{
	_bangHistory.push_back(ofGetSystemTime());
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

	_beatCountdown -= 1;

	if (_beatCountdown > 1) {
		_isSendBeat = false;
	}

	if (_beatCountdown < 1)
	{
		_isSendBeat = true;
		_beatCountdown = _frequency.value;
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