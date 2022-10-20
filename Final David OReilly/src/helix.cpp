#include "helix.h"

Helix::Helix() {
}

void Helix::setup(int _vlength, float _rad, float _zheight, int _zoffset, float _domain, float _rot, float _rotstep, float _rotoffset) {

	vlength = _vlength;
	rad = _rad;
	zheight = _zheight;
	zoffset = _zoffset;
	domain = _domain;
	rot = _rot;
	rotstep = _rotstep;
	rotoffset = _rotoffset;
}

void Helix::update(float _rotscale) {

	rotscale = _rotscale;

	if (rot >= domain) {
		rot = 0;
	}
	else {
		rot += (rotscale)*rotstep;
	}
}

void Helix::draw() {


}

float Helix::x(int _index, float _scaleX) {
	
	index = _index;
	scaleX = _scaleX;
	float t = ofMap(index, 0, vlength, 0, domain);
	return (rad * (cos(scaleX*(t + rot) + rotoffset)));
}


float Helix::y(int _index, float _scaleY) {

	index = _index;
	scaleY = _scaleY;
	float t = ofMap(index, 0, vlength, 0, domain);
	return (rad * (sin(scaleY*(t + rot) + rotoffset)));
}

float Helix::z(int _index) {

	index = _index;
	float t = ofMap(index, 0, vlength, 0, domain);
	float zadd = t + rot;
	if (zadd > domain) {
		zadd = zadd - (domain);
	}
	return (zheight * (zadd) - zoffset);
}

float Helix::xrot(int _index) {

	return 0;
}

float Helix::yrot(int _index) {

	return 0;
}

float Helix::zrot(int _index) {

	index = _index;
	float t = ofMap(index, 0, vlength, 0, domain);
	return ((t + rot + rotoffset) * (180 / PI) + 90);
}