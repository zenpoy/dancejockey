#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){

	openni::Status rc = openni::OpenNI::initialize();
	if (rc != openni::STATUS_OK)
	{
		printf("Initialize failed\n%s\n", openni::OpenNI::getExtendedError());
		return;
	}

	openni::Device device;
	rc = device.open("C:\\f\\q.oni");


	nite::NiTE::initialize();

	niteRc = userTracker.create();
	if (niteRc != nite::STATUS_OK)
	{
		printf("Couldn't create user tracker\n");
		return;
	}
	printf("\nStart moving around to get detected...\n(PSI pose may be required for skeleton calibration, depending on the configuration)\n");


}

//--------------------------------------------------------------
void testApp::update(){

	niteRc = userTracker.readFrame(&userTrackerFrame);
	if (niteRc != nite::STATUS_OK)
	{
		printf("Get next frame failed\n");
		return;
	}

	const nite::Array<nite::UserData>& users = userTrackerFrame.getUsers();
	for (int i = 0; i < users.getSize(); ++i)
	{
		const nite::UserData& user = users[i];

		if (user.isNew())
		{
			userTracker.startSkeletonTracking(user.getId());
		}
		else if (user.getSkeleton().getState() == nite::SKELETON_TRACKED)
		{
			const nite::SkeletonJoint& head = user.getSkeleton().getJoint(nite::JOINT_HEAD);
			if (head.getPositionConfidence() > .5)
				printf("%d. (%5.2f, %5.2f, %5.2f)\n", user.getId(), head.getPosition().x, head.getPosition().y, head.getPosition().z);
		}
	}

}

//--------------------------------------------------------------
void testApp::draw(){

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

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
	nite::NiTE::shutdown();
}
