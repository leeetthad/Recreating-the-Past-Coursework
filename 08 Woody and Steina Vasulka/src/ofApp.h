#pragma once

#include "ofMain.h"
#include "ofxCv.h"

using namespace ofxCv;

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
		ofVideoGrabber grabber;
		ofImage camGray;
		ofImage bgGray;
		ofImage diffImg;
		ofImage threshImg;

		bool bRecordBg = false;
		float brightness;
		float brightSmooth;

		ofEasyCam cam;

		int rad;
		int s;
		int div;

		float linewidthstep;
};
