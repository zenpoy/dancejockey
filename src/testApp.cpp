#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){
	ofSetVerticalSync(true);
	ofSetCircleResolution(100);
	jockey.setup();
	circlePainter.setup();
	
}

//--------------------------------------------------------------
void testApp::update(){
	circlePainter.update(); // todo 1. ofAttach(draw...)
}

//--------------------------------------------------------------
void testApp::draw(){
	ofBackground(0);
	circlePainter.draw(); // todo 1. ofAttach(draw...)
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
}
