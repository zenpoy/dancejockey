#include "testApp.h"

#include "..\HandJockey.h"
#include "..\SynthPlayer.h"
#include "..\GestureJockey.h"
#include "..\MouseJockey.h"
#include "..\Metronome.h"
#include "..\CirclePainter.h"


//--------------------------------------------------------------
void testApp::setup(){
	ofSetFrameRate(60);
	ofSetVerticalSync(true);
	ofSetCircleResolution(100);
	sceneCam.setGlobalPosition(0,0,2000);

	instruments.push_back(new HandJockey);
	instruments.push_back(new GestureJockey);
	instruments.push_back(new MouseJockey);
	instruments.push_back(new CirclePainter);
	instruments.push_back(new SynthPlayer);
	instruments.push_back(new Metronome);


	for (vector<Instrument*>::iterator it = instruments.begin(); it != instruments.end(); ++it)
	(*it)->setup();

}

//--------------------------------------------------------------
void testApp::update(){
	for (vector<Instrument*>::iterator it = instruments.begin(); it != instruments.end(); ++it)
		(*it)->update();
}

//--------------------------------------------------------------
void testApp::draw(){
	ofBackground(0);

	sceneCam.begin();
	for (vector<Instrument*>::iterator it = instruments.begin(); it != instruments.end(); ++it)
		(*it)->draw3D();
	sceneCam.end();

	for (vector<Instrument*>::iterator it = instruments.begin(); it != instruments.end(); ++it)
		(*it)->draw2D();

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

	switch(key)
	{
	case 'f':
		ofToggleFullscreen();
		break;
	}
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){
	

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}

void testApp::exit()
{
	for (vector<Instrument*>::reverse_iterator rit = instruments.rbegin(); rit != instruments.rend(); ++rit)
		(*rit)->exit();
}
