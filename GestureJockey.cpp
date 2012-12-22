#include "GestureJockey.h"

void GestureJockey::handUpdate( ofPoint& p )
{
	_positionHistory.push_front(ofPoint(p));
	if (_positionHistory.size() <= _historySize)
	{
		return;
	}
	else
	{
		_positionHistory.pop_back();
	}

	//process
	// example: calculate speed
	ofPoint velocityF = _positionHistory[_historySize / 2] - _positionHistory.front();
	ofPoint velocityB = _positionHistory.back() - _positionHistory[_historySize / 2];

	float translation = (velocityB + velocityF).length();
	float acceleration = velocityB.getNormalized().dot(velocityF.getNormalized());

	printf("%f\n", translation);
	printf("%f\n", acceleration);

	if (true)
	{
		bool x = true;
		ofNotifyEvent(getJockeyEvents().onGesture, x); //TODO send id
	}
}