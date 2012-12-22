#pragma once



class Beat
{
	unsigned long long timeStamp;
public:
	unsigned long long getTimeStamp() const { return timeStamp; }
	void setTimeStamp(unsigned long long val) { timeStamp = val; }

	//TODO: getProgress
};

class Tempo
{
	float _bpm;
	struct Signature
	{
		//TODO: add support for additive (3+2+3), mixed (3/8 + 5/8), etc:
		// http://en.wikipedia.org/wiki/Time_signature
		int nominator;	//	3/4 or 4/4
		int denominator;	//	3/8 or 3/4 
		Signature (int nom, int denom) : nominator(nom), denominator(denom){}
	} signature;

public:
	Tempo() : _bpm(120), signature(4,4)
	{
	}

	float getBpm() const {return _bpm;} 
	void setBpm(float bpm) {_bpm = bpm * signature.nominator;}
	float getBeatLength() const {return 60.0f / getBpm();}
	void setBeatLength(float sec) {setBpm(60.0f / sec);}
	unsigned long long getBeatLengthMillis() {return unsigned long long(getBeatLength() * 1000.0f);}
	void setBeatLengthMillis(unsigned long long millis) {setBeatLength(millis / 1000.0f);}
	int getNominator() {return signature.nominator;}

};
