#include "RoseCurve.h"

RoseCurve::RoseCurve() {
}

void RoseCurve::setup(int _x, int _y, int _rad, int _radstep, float _n, float _d, float _t, float _tshift, float _tstep, float _rot, float _rotstep) {
	x = _x;
	y = _y;
	rad = _rad;
	radstep = _radstep;
	n0 = _n;
	n = _n;
	d0 = _d;
	d = _d;
	kshift = 0;
	tstepshift = 0;
	t = _t;
	tshift = _tshift;
	tstep0 = _tstep;
	tstep = _tstep;
	rot = _rot;
	rotstep = _rotstep;
}

void RoseCurve::update() {

	if (rad < 400) {
		rad += radstep;
	}
	else {
		rad = 700;
	}

	t += tshift;

	rot = rot + rotstep;

	kshift += 0.001;

	n = n0 + 4*(cos(kshift) - 1);
	d = d0 + 4*(cos(kshift) - 1);

	tstepshift += 0.01;

	tstep = tstep0 + 0.01 * (sin(tstepshift));
}

void RoseCurve::draw() {

	float k = n / d;

	for (float theta = t; theta < (n*2*(PI)/k + t); theta += tstep) {

		int i = (int)(theta * 100);
		//ofSeedRandom(i);
		//color = ofColor(ofRandom(91, 255), ofRandom(38, 76), ofRandom(160, 255));
		color = ofColor(125 + 50 * (sin(theta) - 1), 255 + 50 * (sin(theta) - 1), 220 + 50 * (cos(theta) - 1));
		ofSetColor(color);
		ofFill();
		float PosX = x + rad * cos(k * 1.5*theta) * cos(1.5*theta);
		float PosY = y + rad * cos(k * 1.5*theta) * sin(1.5*theta);

		ofDrawCircle(((PosX - x)*cos(rot) - (PosY - y)*sin(rot)) + x, ((PosX - x) *sin(rot) + (PosY - y) *cos(rot) + y), 8 + (4 * (sin(theta)+0.5))); //
	}
}
