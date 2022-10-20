#pragma once

#include "ofMain.h"
#include "ofxShadertoy.h"
#include "ofxAssimpModelLoader.h"
#include "ofVboMesh.h"
#include "helix.h"

class ofApp : public ofBaseApp {

public:
	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);

	ofSoundPlayer soundPlayer;

	ofFbo bgfbo;
	float bgrotate;

	int modeldiv;
	int helixct;
	float helixstep;
	float modeldivstep;
	float posstep;

	vector <float> rotation;
	vector <float> rotstep;
	vector <float> domain;
	vector <float> rad;
	vector <float> zheight;
	vector <float> rotoffset;
	vector <int> index;
	vector <float> scale;
	vector <float> rotationx;
	vector <float> rotationy;

	float posx;
	float posy;
	
	ofxShadertoy shadertoy;

	ofCamera cam;
	ofEasyCam cam2;

	ofxAssimpModelLoader model;

	ofLight light;

	vector <Helix> helixAll;
	vector <vector <ofxAssimpModelLoader>> modelAll;

};
