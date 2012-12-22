#pragma once
#include "ofEvents.h"
#include "JockeyTypes.h"

class Jockey {};

class JockeyEvents{
public:
	ofEvent<float> velocityUpdate;
	ofEvent<unsigned long long> bang;
	ofEvent<ofPoint> handUpdate;
	ofEvent<bool> onGesture;
	ofEvent<Tempo> tempo;
	ofEvent<Beat> beat;
	ofEvent<float> click;

	//TODO: more events here...
};

JockeyEvents& getJockeyEvents();


template<class ListenerClass>
void registerJockeyVelocityEvents(ListenerClass * listener){
	ofAddListener(getJockeyEvents().velocityUpdate, listener, &ListenerClass::velocityUpdate);
}

template<class ListenerClass>
void registerJockeyBangEvents(ListenerClass * listener){
	ofAddListener(getJockeyEvents().bang, listener, &ListenerClass::bang);
}

template<class ListenerClass>
void registerHandJockeyEvents(ListenerClass * listener){
	ofAddListener(getJockeyEvents().handUpdate, listener, &ListenerClass::handUpdate);
}

template<class ListenerClass>
void registerGestureJockeyEvents(ListenerClass * listener){
	ofAddListener(getJockeyEvents().onGesture, listener, &ListenerClass::onGesture);
}

template<class ListenerClass>
void registerMetronomeEvents(ListenerClass * listener){
	ofAddListener(getJockeyEvents().beat, listener, &ListenerClass::beat);
	ofAddListener(getJockeyEvents().tempo, listener, &ListenerClass::tempo);
	ofAddListener(getJockeyEvents().click, listener, &ListenerClass::click);
}

