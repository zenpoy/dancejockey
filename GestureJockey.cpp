#include "GestureJockey.h"
#include "ofGraphics.h"

void GestureJockey::handUpdate( ofPoint& p )
{
	mutex.lock();
	_positionHistory.push_front(ofPoint(p));
	mutex.unlock();
	if (_positionHistory.size() <= _historySize)
	{
		return;
	}
	else
	{
		mutex.lock();
		_positionHistory.pop_back();
		mutex.unlock();

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


void GestureJockey::draw3D()
{
	mutex.lock();
	ofPushMatrix();
	for (int i = 0; i < _positionHistory.size(); i++)
	{
		ofSphere(_positionHistory[i], (_historySize - i));
	}
	ofPopMatrix();
	mutex.unlock();
}
