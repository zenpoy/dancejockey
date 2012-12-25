#pragma once
#include "Jockey.h"

template <class T>
struct Value
{
	Value(T init, float changeRate) : init(init), changeRate(changeRate), value(init), target(init)
	{}
	T init;
	float changeRate;
	T value;
	T target;
};

class Instrument
{
public:
	virtual void setup() {};
	virtual void update() {};
	virtual void draw2D() {};
	virtual void draw3D() {};
	virtual void exit() {};
};