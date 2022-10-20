#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	ofHideCursor();

	//grabber.listDevices();
	grabber.setDeviceID(0);
	grabber.initGrabber(960, 540);

	haar.setup("haarcascade_lefteye_2splits.xml");
	//haar.setup("haarcascade_smile.xml");
	haar.setScaleHaar(2);

	camGray.allocate(grabber.getWidth(), grabber.getHeight(), OF_IMAGE_GRAYSCALE);
	bgGray.allocate(grabber.getWidth(), grabber.getHeight(), OF_IMAGE_GRAYSCALE);
	diffImg.allocate(grabber.getWidth(), grabber.getHeight(), OF_IMAGE_GRAYSCALE);
}

//--------------------------------------------------------------

void ofApp::update(){

	grabber.update();

	if (grabber.isFrameNew()) {

		convertColor(grabber, camGray, CV_RGB2GRAY);
		camGray.update();

		if (bRecordBg) {
			bgGray.setFromPixels(camGray.getPixels());
			bgGray.update();
			bRecordBg = false;
		}

		absdiff(camGray, bgGray, diffImg);
		diffImg.update();

		threshImg.setFromPixels(diffImg.getPixels());
		threshold(threshImg, mouseX);
		threshImg.update();

		finder.setSortBySize(true);
		finder.findContours(threshImg);
		color.setFromPixels(grabber.getPixels());
		gray = color;
		haar.findHaarObjects(gray);
	}

	if (historytoggle == false) {
		limit = 500;
	}

	if (historytoggle) {
		limit = 0;
		history = blank;
		historytoggle = false;
	}
}

//--------------------------------------------------------------
void ofApp::draw(){

	/*grabber.draw(0, 0);
	camGray.draw(grabber.getWidth(), 0);
	bgGray.draw(0, grabber.getHeight());
	diffImg.draw(grabber.getWidth(), grabber.getHeight());
	threshImg.draw(grabber.getWidth() * 2, 0);*/
	//threshImg.draw(0, 0);

	if (finder.size() > 0) {
		ofSetColor(75);
		finder.getPolyline(0).draw();
		ofSetColor(255);
	}

	for (int i = 0; i < haar.blobs.size(); i++) {
		ofSetColor(255);
		ofNoFill();
		if (haar.blobs.size() > 0) {
			eyeRect = haar.blobs[i].boundingRect;
			eye = eyeRect.getPosition();
		}
		if (i == 1) {
			break;
		}
	}

	pointerSmoothed = 0.85 * pointerSmoothed + 0.15 * eye;

	history.addVertex(pointerSmoothed);
	if (history.size() > limit) {
		history.getVertices().erase(history.getVertices().begin());
	}

	ofFill;
	for (int j = 0; j < history.size(); j++) {
		ofDrawCircle(history[j], 3);
	}
	ofNoFill;

	ofSetColor(255, 0, 0);
	ofFill;
	if (haar.blobs.size() > 0) {
		ofDrawCircle(eye, 6);
	}
	ofNoFill;
	ofSetColor(255);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

	if (key == ' ') {
		bRecordBg = true;
	}

	if (key == 'm') {
		historytoggle = true;
	}
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
