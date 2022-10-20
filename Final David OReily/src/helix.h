#pragma once
#ifndef _HELIX
#define _HELIX

#include "ofMain.h"

class Helix
{
public:

	void setup(int _vlength, float _rad, float _zheight, int _zoffset, float _domain, float _rot, float _rotstep, float _rotoffset);
	void update(float _rotscale);
	void draw();
	float x(int _index, float _scaleX);
	float y(int _index, float _scaleY);
	float z(int _index);
	float xrot(int _index);
	float yrot(int _index);
	float zrot(int _index);

	float rotscale;
	int index;
	float scaleX;
	float scaleY;
	int vlength;
	float rad;
	float zheight;
	int zoffset;
	float domain;
	float rot;
	float rotstep;
	float rotoffset;


	Helix();

private:

};
#endif