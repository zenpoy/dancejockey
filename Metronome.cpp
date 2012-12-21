#include "Metronome.h"
#include "ofGraphics.h"

void Metronome::bang(unsigned long long& t)
{
	_bangHistory.push_front(t);
	if (_bangHistory.size() > 2)
	{
		unsigned long long diff = _bangHistory[0] - _bangHistory[1];
		if (diff < 3000)
			_IntervalHistory.push_front(diff);
		else
			_IntervalHistory.clear();

		_bangHistory.pop_back();
	}


	if (_IntervalHistory.size() <= _historySize)
	{
		return;
	}
	else
	{
		unsigned long long intervalAverage = 0;
		for (int i=0; i < _IntervalHistory.size(); i++)
		{
			intervalAverage += _IntervalHistory[i];
		}

		if (1) //check if stdev is not too high
		{
			_tempo.setBeatLengthMillis(intervalAverage);
			ofNotifyEvent(getJockeyEvents().tempo, _tempo); //TODO send id
		}
		_IntervalHistory.pop_back();
	}
}

void Metronome::update()
{
	unsigned long long now = ofGetSystemTime();
	float diffSec = float(now - _beat.getTimeStamp()) / 1000.0f;
	float progress = (diffSec / _tempo.getBeatLength());

	if (progress > 1.0)
	{
		_beat.setTimeStamp(now);
		ofNotifyEvent(getJockeyEvents().beat, _beat); //TODO send id
	}

}

void Metronome::draw()
{
	ofPushStyle();
	
	/*
	TODO:
	//////////////////////////////////////////////////////////////////////////
	ofDrawBitmapString("IntervalHistory", 0, 0);

	for (int i = 0; i < _IntervalHistory.size(); i++)
	{
		const int h = 10;
		const int hSpace = 3;
		const int x = 20;
		const int y = i * (h+hSpace);
		ofSetColor(0, 255, 128);
		ofRect(x, y, _IntervalHistory[i], h);
		
		ofSetColor(128);
		ofDrawBitmapString(ofToString(_IntervalHistory[i]), x, y);

	}
	*/

	/*
	stringstream ss;

	ss << "bangs"<< endl;
	for (int i = 0; i < _bangHistory.size(); i++)
		ss << _bangHistory[i] << endl;

		ss << "intervals"<< endl;
	for (int i = 0; i < _IntervalHistory.size(); i++)
		ss << _IntervalHistory[i] << endl;
	ofDrawBitmapString(ss.str(), 0, 0);
	
	*/

	ofPopStyle();
}