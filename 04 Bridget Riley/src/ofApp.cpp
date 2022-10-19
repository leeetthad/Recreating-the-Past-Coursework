#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	ofHideCursor();
	ofBackground(192, 209, 216);
	dark[0] = 85;
	dark[1] = 84;
	dark[2] = 90;
	light[0] = 191 + 5;
	light[1] = 208 + 5;
	light[2] = 213 + 5;
	aX = 800;
	aY = 800;

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

	for (int y = 0; y < 23; y++) {

		if (y % 2 == 0) {

			for (int x = 0; x < 23; x++) {

				if (x % 2 == 0) {

					posY = ofMap(y, 0, 22, 75, ofGetHeight() - 75);
					posX = ofMap(x, 0, 22, 75, ofGetWidth() - 75);

					//float dY = abs(posY - mouseY);
					//float dY = abs(posY - aY + 400 * sin(ofGetElapsedTimef()/3));
					float dY = abs(posY - aY - 400 * sin(ofGetElapsedTimef() / 3));
					dY = ofMap(dY, 0, (ofGetHeight() - 150) / 2, 0, 90);

					ofVec2f p1(posX, posY);
					//ofVec2f p0(mouseX, mouseY);
					//ofVec2f p0(aX + 400*cos(ofGetElapsedTimef() / 3), aY + 400 * sin(ofGetElapsedTimef() / 3));
					ofVec2f p0(aX + 400 * sin(ofGetElapsedTimef() / 3), aY - 400 * sin(ofGetElapsedTimef() / 3));

					float dist = p1.distance(p0);
					float maxD = (sqrt((ofGetHeight() - 150)* (ofGetHeight() - 150) + (ofGetWidth() - 150)* (ofGetWidth() - 150))) / 2;

					int r = ofMap(dist, 0, maxD, 0, light[0] - dark[0]);
					int g = ofMap(dist, 0, maxD, 0, light[1] - dark[1]);
					int b = ofMap(dist, 0, maxD, 0, light[2] - dark[2]);

					ofPushMatrix();

					ofSetColor(dark[0] + r, dark[1] + g, dark[2] + b);
					//ofSetColor(255, 255, 255);
					ofFill();

					ofTranslate(posX, posY, 0);
					ofRotateZDeg(-(90 - dY));
					ofDrawEllipse(0, 0, 50, 30);

					ofPopMatrix();
				}
			}
		}

		else {

			for (int x = 0; x < 23; x++) {

				if (x % 2 == 1) {

					posY = ofMap(y, 0, 22, 75, ofGetHeight() - 75);
					posX = ofMap(x, 0, 22, 75, ofGetWidth() - 75);

					//float dY = abs(posY - mouseY);
					//float dY = abs(posY - aY + 400 * sin(ofGetElapsedTimef() / 3));
					float dY = abs(posY - aY - 400 * sin(ofGetElapsedTimef() / 3));
					dY = ofMap(dY, 0, (ofGetHeight() - 150) / 2, 0, 90);

					ofVec2f p1(posX, posY);
					//ofVec2f p0(mouseX, mouseY);
					//ofVec2f p0(aX + 400 * cos(ofGetElapsedTimef() / 3), aY + 400 * sin(ofGetElapsedTimef() / 3));
					ofVec2f p0(aX + 400 * sin(ofGetElapsedTimef() / 3), aY - 400 * sin(ofGetElapsedTimef() / 3));

					float dist = p1.distance(p0);
					float maxD = (sqrt((ofGetHeight() - 150) * (ofGetHeight() - 150) + (ofGetWidth() - 150) * (ofGetWidth() - 150))) / 2;

					int r = ofMap(dist, 0, maxD, 0, light[0] - dark[0]);
					int g = ofMap(dist, 0, maxD, 0, light[1] - dark[1]);
					int b = ofMap(dist, 0, maxD, 0, light[2] - dark[2]);

					ofPushMatrix();

					ofSetColor(dark[0] + r, dark[1] + g, dark[2] + b);
					//ofSetColor(255, 255, 255);
					ofFill();

					ofTranslate(posX, posY, 0);
					ofRotateZDeg(-(90 - dY));
					ofDrawEllipse(0, 0, 50, 30);

					ofPopMatrix();
				}
			}
		}

	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
