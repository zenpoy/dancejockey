#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){
	ofSetFrameRate(60);
	ofSetVerticalSync(true);
	ofSetCircleResolution(100);
	sceneCam.setGlobalPosition(0,0,2000);

	handJockey.setup();
	gestureJockey.setup();
	mouseJockey.setup();
	circlePainter.setup();
	synthPlayer.setup();
	metronome.setup();
	
}

//--------------------------------------------------------------
void testApp::update(){
	circlePainter.update(); // todo 1. ofAttach(draw...)
	metronome.update(); // todo 1. ofAttach(draw...)
}

//--------------------------------------------------------------
void testApp::draw(){
	ofBackground(0);

	sceneCam.begin();
	gestureJockey.draw3D();
	sceneCam.end();

	circlePainter.draw2D(); // todo 1. ofAttach(draw...)
	metronome.draw2D();

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
	handJockey.exit();
}
