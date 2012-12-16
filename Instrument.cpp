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
	ofPushMatrix();
	ofPushStyle();
	ofSetColor(255, 0, 0);
	_fill ? ofFill() : ofNoFill();

	ofPoint screenCenter(ofGetWindowWidth() / 2, ofGetWindowHeight() / 2);
	ofTranslate(screenCenter);
	ofCircle(ofPoint(), _radius.value);
	
	ofPopStyle();
	ofPopMatrix();
}

void CirclePainter::velocityUpdate( float& velocity )
{
	_radius.target += velocity; 
}

void CirclePainter::beat( InstrumentEventArgs& )
{
	_fill = !_fill;
	_radius.value *= 2.2;
}


MetronomeEvents Metronome::events;

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

	//TODO: Change this to use timer events
	_beatCountdown--;

	if (_beatCountdown > 1) {
		_isSendBeat = false;
	}

	if (_beatCountdown < 1)
	{
		_isSendBeat = true;
		_beatCountdown = _frequency.value;
		InstrumentEventArgs beat;
		ofNotifyEvent(events.beat, beat); //TODO send id
	}
}

void Metronome::draw()
{
}