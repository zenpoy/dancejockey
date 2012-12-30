#pragma once

#include "ofEvents.h"
#include "JockeyTypes.h"

class JockeyEvents{
public:
	ofEvent<float> velocityUpdate;
	ofEvent<unsigned long long> bang;
	ofEvent<TrackedPoint> handUpdate;
	ofEvent<bool> onGesture;
	ofEvent<Tempo> tempo;
	ofEvent<Tempo> beat;

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
	ofAddListener(getJockeyEvents().beat, listener, &ListenerClass::onBeat);
	ofAddListener(getJockeyEvents().tempo, listener, &ListenerClass::onTempoChange);
}