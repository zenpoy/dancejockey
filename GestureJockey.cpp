#include "GestureJockey.h"
#include "ofGraphics.h"

void GestureJockey::handUpdate( TrackedPoint& p )
{
	if (p.isLost())
	{
		mutex.lock();
		_positionHistory.clear();
		sum = ofPoint();
		avgSqrDist = 0;

		mutex.unlock();		
		return;
	}

	mutex.lock();
	_positionHistory.push_front(p);
	sum += p.pos;
	if (_positionHistory.size() > _historySize)
	{
		sum -= _positionHistory.back().pos;
		_positionHistory.pop_back();
	}
	mutex.unlock();		

	if (_positionHistory.size() < _historySize)
	{
		return;
	}

	avg = sum / _positionHistory.size();
	avgSqrDist = 0;
	for(int i = 0; i < _positionHistory.size(); i++)
	{
		avgSqrDist += (_positionHistory[i].pos - avg).length(); 
	}



	//process
	// example: calculate speed
	ofPoint velocityF = _positionHistory[_historySize / 2].pos - _positionHistory.front().pos;
	ofPoint velocityB = _positionHistory.back().pos - _positionHistory[_historySize / 2].pos;

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
	ofPushMatrix();

	mutex.lock();	
	for(int i = _positionHistory.size() - 1; i > 1; i--)
	{
		float p = float(i) / (_historySize - 1);
		ofSetColor(ofColor::fromHsb(255 * p, 255, 255, 1-p));
		ofSphere(_positionHistory[i].pos, (_historySize - i) / 2);
		ofLine(_positionHistory[i].pos, _positionHistory[i-1].pos);
	}
	ofSetColor(ofColor::red);
	ofSphere(sum / _positionHistory.size(), 5 + avgSqrDist / 100);

	mutex.unlock();

	ofPopMatrix();
}
