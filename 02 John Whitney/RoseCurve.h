#pragma once
#ifndef _ROSECURVE
#define _ROSECURVE

#include "ofMain.h"

class RoseCurve
{
public:

	void setup(int _x, int _y, int _rad, int _radstep, float _n, float _d, float _t, float _tshift, float _tstep, float _rot, float _rotstep);
	void update();
	void draw();

	int rad;
	int radstep;
	int x;
	int y;
	float n;
	float n0;
	float d;
	float d0;
	float k;
	float kshift;
	float t;
	float tshift;
	float tstep0;
	float tstepshift;
	float tstep;
	float rot;
	float rotstep;
	ofColor color;

	RoseCurve();

private:

};
#endif

