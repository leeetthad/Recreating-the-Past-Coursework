#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){


	ofDirectory br2049;
	br2049.listDir("cp2077")
		;
	for (int i = 0; i < br2049.size(); i++) {
		
		ofImage img;
		br2049img.push_back(img);
		br2049img.back().load(br2049.getPath(i));
		cout << "loaded" << i << " of " << br2049.size() << endl;

		ofRectangle targetDim(0, 0, 1920, 1080);
		ofRectangle imageDim(0, 0, br2049img.back().getWidth(), br2049img.back().getHeight());

		targetDim.scaleTo(imageDim);
		br2049img.back().crop(targetDim.x, targetDim.y, targetDim.width, targetDim.height);
		br2049img.back().resize(1920, 1080);
	}

	average.allocate(1920, 1080, OF_IMAGE_COLOR);

	for (int i = 0; i < 1920; i++) {
		for (int j = 0; j < 1080; j++) {

			float sumRed = 0;
			float sumBlue = 0;
			float sumGreen = 0;
			for (int k = 0; k < br2049img.size(); k++) {
				ofColor color = br2049img[k].getColor(i, j);
				sumRed += color.r;
				sumBlue += color.b;
				sumGreen += color.g;
			}

			sumRed /= (float)br2049img.size();
			sumBlue /= (float)br2049img.size();
			sumGreen /= (float)br2049img.size();
			average.setColor(i, j, ofColor(sumRed, sumGreen, sumBlue));
		}
	}

	average.update();
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

	average.draw(0, 0);
	//br2049img[ofGetFrameNum() % br2049img.size()].draw(0, 0);
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
