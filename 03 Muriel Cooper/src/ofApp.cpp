#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	ofSetFrameRate(120);
	ofSetBackgroundColor(255, 255, 255);
	font.load("Helvetica-Bold.ttf", 185, true, true, true);
	font.setLetterSpacing(0.65);
	font.setSpaceSize(1.2);
	//cam.enableOrtho();
}

//--------------------------------------------------------------
void ofApp::update(){
	font.setLetterSpacing(0.65 + 0.1 * sin(0.1 * t));
	font.setSpaceSize(1.2 - (abs((0.6)*(sin(0.6*t)))));
}

//--------------------------------------------------------------
void ofApp::draw(){

	t = 0.1 * ofGetElapsedTimef();
	//t = mouseX / 10;
	//t = 0;
	a = 175;

	ofEnableBlendMode(OF_BLENDMODE_SUBTRACT);

	//cam.begin();

	vector <ofPath> paths = font.getStringAsPoints("BAUHAUS BAUHAUS BAUHAUS");

	for (int i = 0; i < 4; i++) {
	
		ofPushMatrix();

		ofTranslate(220 + (i*398), 1115 + 1150);
		ofRotate(-90);

		ofSetColor(0, 255, 125, a);
		ofTranslate(15 * sin(0.2 * t), 0);
		for (int i = 0; i < paths.size(); i++) {
			paths[i].draw();
		}

		ofSetColor(255, 80, 20, a);
		ofTranslate((-30) * (cos(0.4 * t)), 5 * sin(0.6 * t));
		for (int i = 0; i < paths.size(); i++) {
			paths[i].draw();
		}

		ofSetColor(0, 0, 255, a);
		ofTranslate(60 * cos(0.6 * t), 5 * sin(0.4 * t));
		for (int i = 0; i < paths.size(); i++) {
			paths[i].draw();
		}

		ofPopMatrix();
	}
	
	for (int i = 0; i < 4; i++) {

		ofPushMatrix();

		//ofScale(1, -1);

		ofTranslate(-155 + (i * 398), 30 - 1150);
		ofRotate(90);
		//ofRotateXDeg(90);

		ofSetColor(0, 255, 125, a);
		ofTranslate(15 * sin(0.2 * t), 0);
		for (int i = 0; i < paths.size(); i++) {
			paths[i].draw();
		}

		ofSetColor(0, 0, 255, a);
		ofTranslate((-30) * (cos(0.4 * t)), 5 * sin(0.6 * t));
		for (int i = 0; i < paths.size(); i++) {
			paths[i].draw();
		}

		ofSetColor(255, 80, 20, a);
		ofTranslate(60 * cos(0.6 * t), 5 * sin(0.4 * t));
		for (int i = 0; i < paths.size(); i++) {
			paths[i].draw();
		}

		ofPopMatrix();
	}
	

	//cam.end();

	ofDisableBlendMode();
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
