#include "Instrument.h"
#include "ofGraphics.h"


void CirclePainter::draw()
{
	ofPushStyle();
	ofSetColor(255, 0, 0);
	ofCircle(100,100, _circleRadius);
	ofPopStyle();
}

void CirclePainter::velocityUpdate( float& velocity )
{
	printf("%f\n", velocity);
	_circleRadius = 10 + velocity;
}
