#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(144);

	ofBackground(0, 0, 0);

	for (int i = 0; i < 16; i++) {
		randomSixteen.push_back(i);
	}

	for (int a = 0; a < s; a++) {

		if (a % 2 == 0) {

			for (int b = (s * a); b < (s * a) + s; b++) {

				ofSeedRandom(mouseX + ofRandom(0,128));
				ofRandomize(randomSixteen);

				int yOffset = m + (a * (4 * m));
				int xOffset = m + ((b % s) * (4 * m));

				for (int i = 0; i < 4; i++) {
					for (int j = 0; j < 4; j++) {
						int k = (4 * i) + j;
						points[b][k].set(xOffset + (m * j), yOffset + (m * i));
					}
				}

				for (int i = 0; i < 16; i++) {
					line.addVertex(points[b][randomSixteen[i]]);
				}

			}
		}

		else {

			for (int b = (s * a); b < (s * a) + s; b++) {

				ofSeedRandom(mouseX + ofRandom(0, 128) + 2);
				ofRandomize(randomSixteen);

				int yOffset = m + (a * (4 * m));
				int xOffset = (((4 * (s - 1)) + 1) * m) - ((b % s) * (4 * m));

				for (int i = 0; i < 4; i++) {
					for (int j = 0; j < 4; j++) {
						int k = (4 * i) + j;
						points[b][k].set(xOffset + (m * j), yOffset + (m * i));
					}
				}

				for (int i = 0; i < 16; i++) {
					line.addVertex(points[b][randomSixteen[i]]);
				}

			}

		}
	}
}

//--------------------------------------------------------------
void ofApp::update() {
	
	if (ptpct < 1000) {
		ptpct += 0.02;
	}
	else {
		line2.clear();
		ptpct = 0;
	}
}

//--------------------------------------------------------------
void ofApp::draw() {

	ofHideCursor();
	ofSetColor(0 ,0,0);
	line.draw();

	ofSetColor(255, 255, 255);
	line2.addVertex(line.getPointAtPercent(ptpct / 1000));
	line2.draw();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
