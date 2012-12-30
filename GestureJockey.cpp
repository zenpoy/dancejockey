#include "GestureJockey.h"
#include "ofGraphics.h"

void GestureJockey::handUpdate( TrackedPoint& p )
{
	if (p.isLost())
	{
		mutex.lock();
		_positionHistory.clear();
		sum = ofPoint();
		sumDistAvg = 0;

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
	
	sumDistAvg = 0;
	minDistAvg = 1e10;
	maxDistAvg = 0;

	for(int i = 0; i < _positionHistory.size(); i++)
	{
		ofPoint diff = (_positionHistory[i].pos - avg);
		float len = diff.length();
		if (len < minDistAvg) minDistAvg = len;
		if (len > maxDistAvg) maxDistAvg = len;

		sumDistAvg += len;
	}
	avgDistAvg = sumDistAvg / _positionHistory.size();


	circlePredictionFactor = avgDistAvg / (maxDistAvg - minDistAvg);
	if (circlePredictionFactor > 2.0f)
	{
		bool x = true;
		ofNotifyEvent(getJockeyEvents().onGesture, x); //TODO send id
	}


	//process
	// example: calculate speed
	ofPoint velocityF = _positionHistory[_historySize / 2].pos - _positionHistory.front().pos;
	ofPoint velocityB = _positionHistory.back().pos - _positionHistory[_historySize / 2].pos;

	float translation = (velocityB + velocityF).length();
	float acceleration = velocityB.getNormalized().dot(velocityF.getNormalized());

	printf("%f\n", translation);
	printf("%f\n", acceleration);

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

	ofNoFill();
	ofSetColor(ofColor::blue);
	ofSphere(avg, 5 + maxDistAvg);

	ofSetColor(ofColor::green);
	ofSphere(avg, 5 + avgDistAvg);

	ofSetColor(ofColor::red);
	ofSphere(avg, 5 + minDistAvg);

	ofSetColor(ofColor::yellow);
	ofSphere(ofPoint(), 5 +  50 * circlePredictionFactor);



	mutex.unlock();

	ofPopMatrix();
}

void GestureJockey::draw2D()
{
	ofDrawBitmapString(ofToString(circlePredictionFactor), 10, 10);
}
