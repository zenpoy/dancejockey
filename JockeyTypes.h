#pragma once
#include "ofUtils.h"

class Tempo
{
	float _bpm;
	int _signature;
	int _counter;
	unsigned long long _timeStamp;

public:
	Tempo() : _bpm(120), _signature(4), _counter(0), _timeStamp(0)
	{
	}

	float getBpm() const {return _bpm;} 
	void setBpm(float bpm) {_bpm = bpm * _signature;}

	float getBeatLength() const {return 60.0f / getBpm();}
	void setBeatLength(float sec) {setBpm(60.0f / sec);}

	unsigned long long getBeatLengthMillis() const {return unsigned long long(getBeatLength() * 1000.0f);}
	void setBeatLengthMillis(unsigned long long millis) {setBeatLength(millis / 1000.0f);}
	

	int getSignature() const {return _signature;}
	int setSignature(int signature) {_signature = signature;}

	int getCounter() const { return _counter; }
	void setCounter(int val) { _counter = val; }

	unsigned long long getTimeStamp() const { return _timeStamp; }
	void setTimeStamp(unsigned long long val) { _timeStamp = val; }
	
	void incrementCounter() 
	{
		_counter++;
		_counter %= _signature;
	}

	float getBeatProgress() 
	{
		return float(ofGetSystemTime() - getTimeStamp()) / getBeatLengthMillis();
	}

	float getBarProgress() 
	{
		return (getBeatProgress() + getCounter()) / getSignature();
	}

	string toString() 
	{
		return 
		"bpm: " + ofToString(_bpm) + "\n" +
		"signature: " + ofToString(_signature) + "\n" +
		"counter: " + ofToString(_counter) + "\n" +
		"timeStamp: " + ofToString(_timeStamp) + "\n";
	}


};